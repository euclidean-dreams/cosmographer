#include <ImpresarioUtils.h>
#include "Config.h"
#include "Cosmographer.h"
#include "vantage/LuciferonVantage.h"
#include "vantage/PalantirVantage.h"
#include "percipient/AnalogoriumPercipient.h"
#include "percipient/VolitiaPercipient.h"

namespace cosmographer {

int bootstrap() {
    std::string configFilePath = "./config.yml";
    impresarioUtils::Bootstrapper bootstrapper(configFilePath, 1);

    // percipient
    auto essentiology = std::make_shared<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>>();
    auto analogoriumSocket = std::make_unique<impresarioUtils::NetworkSocket>(
            bootstrapper.getZmqContext(),
            ANALOGORIUM_ENDPOINT,
            zmq::socket_type::sub,
            false
    );
    analogoriumSocket->setSubscriptionFilter(ImpresarioSerialization::Identifier::essentia);
    auto analogoriumPercipient = std::make_unique<AnalogoriumPercipient>(move(analogoriumSocket), essentiology);
    auto analogoriumPercipientThread = impresarioUtils::Circlet::begin(move(analogoriumPercipient));

    auto axiomologyArbiter = std::make_shared<impresarioUtils::Arbiter<const impresarioUtils::Parcel>>();
    auto phenomenology = std::make_shared<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>>();
    auto volitiaSocket = std::make_unique<impresarioUtils::NetworkSocket>(
            bootstrapper.getZmqContext(),
            VOLITIA_ENDPOINT,
            zmq::socket_type::sub,
            false
    );
    volitiaSocket->setSubscriptionFilter(ImpresarioSerialization::Identifier::axiomology);
    volitiaSocket->setSubscriptionFilter(ImpresarioSerialization::Identifier::phenomenon);
    auto volitiaPercipient = std::make_unique<VolitiaPercipient>(move(volitiaSocket), axiomologyArbiter, phenomenology);
    auto volitiaPercipientThread = impresarioUtils::Circlet::begin(move(volitiaPercipient));


    // wait for first axiomology
    while (axiomologyArbiter->take() == nullptr) {
        impresarioUtils::sleep(5000);
        LOGGER->info("waiting to receive first axiomology");
    }

    // paradigm
    Paradigm::initialize(move(axiomologyArbiter));

    // vantage
    std::unique_ptr<Vantage> vantage;
    if (VANTAGE_TYPE == 0) {
        auto luciferonSocket = std::make_unique<impresarioUtils::NetworkSocket>(
                bootstrapper.getZmqContext(),
                LUCIFERON_ENDPOINT,
                zmq::socket_type::pub,
                true
        );
        vantage = std::make_unique<LuciferonVantage>(move(luciferonSocket));
    } else if (VANTAGE_TYPE == 1) {
        auto palantirSocket = std::make_unique<impresarioUtils::NetworkSocket>(
                bootstrapper.getZmqContext(),
                PALANTIR_ENDPOINT,
                zmq::socket_type::pub,
                true
        );
        vantage = std::make_unique<PalantirVantage>(move(palantirSocket));
    } else {
        LOGGER->error("invalid vantage type: {}", VANTAGE_TYPE);
        return -1;
    }

    // cosmographer
    auto cosmographer = std::make_unique<Cosmographer>(move(vantage), move(essentiology), move(phenomenology));
    auto cosmographerThread = impresarioUtils::Circlet::begin(move(cosmographer));

    // go time!
    cosmographerThread->join();
    analogoriumPercipientThread->join();
    volitiaPercipientThread->join();

    return 0;
}

}

int main() {
    return cosmographer::bootstrap();
}
