#include "Bootstrapper.h"

namespace cosmographer {

void Bootstrapper::boot() {
    // general
    Config::initialize();
    auto config = Config::getInstance();
    spdlog::stdout_color_mt(config.getLoggerName());
    zmq::context_t context(1);

    // packet receivers
    auto conductorSocket = std::make_unique<impresarioUtils::NetworkSocket>(
            context,
            config.getConductorEndpoint(),
            zmq::socket_type::sub,
            false
    );
    conductorSocket->setSubscriptionFilter(ImpresarioSerialization::Identifier::displaySignal);
    auto conductorPacketReceiver = std::make_unique<impresarioUtils::PacketReceiver>(move(conductorSocket));

    auto fasciaSocket = std::make_unique<impresarioUtils::NetworkSocket>(
            context,
            config.getFasciaEndpoint(),
            zmq::socket_type::sub,
            false
    );
    fasciaSocket->setSubscriptionFilter(ImpresarioSerialization::Identifier::floatMorsel);
    fasciaSocket->setSubscriptionFilter(ImpresarioSerialization::Identifier::floatArrayMorsel);
    auto fasciaPacketReceiver = std::make_unique<impresarioUtils::PacketReceiver>(move(fasciaSocket));

    auto packetReceivers = std::make_unique<std::vector<std::unique_ptr<impresarioUtils::PacketReceiver>>>();
    packetReceivers->push_back(move(conductorPacketReceiver));
    packetReceivers->push_back(move(fasciaPacketReceiver));

    // lattice arbiter
    auto latticeArbiter = std::make_shared<LatticeArbiter>();

    // cosmographer
    auto cosmographer = std::make_unique<Cosmographer>(move(packetReceivers), latticeArbiter);
    auto cosmographerThread = impresarioUtils::Circlet::begin(move(cosmographer));

    // vantage
    auto luciferonSocket = std::make_unique<impresarioUtils::NetworkSocket>(
            context,
            config.getLuciferonEndpoint(),
            zmq::socket_type::pub,
            true
    );
    auto luciferonVantage = std::make_unique<LuciferonVantage>(latticeArbiter, move(luciferonSocket));
    auto luciferonThread = impresarioUtils::Circlet::begin(move(luciferonVantage));

    auto palantirSocket = std::make_unique<impresarioUtils::NetworkSocket>(
            context,
            config.getPalantirEndpoint(),
            zmq::socket_type::pub,
            true
    );
    auto palantirVantage = std::make_unique<PalantirVantage>(latticeArbiter, move(palantirSocket));
    auto palantirThread = impresarioUtils::Circlet::begin(move(palantirVantage));

    // go time!
    cosmographerThread->join();
    luciferonThread->join();
    palantirThread->join();
}

}
