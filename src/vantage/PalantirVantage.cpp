#include "PalantirVantage.h"

namespace cosmographer {

PalantirVantage::PalantirVantage(std::unique_ptr<impresarioUtils::NetworkSocket> socket)
        : socket{move(socket)},
          tickInterval{PALANTIR_TICK_INTERVAL} {

}

void PalantirVantage::send(const Lattice &lattice) {
    std::vector<ImpresarioSerialization::Color> sendBuffer{};
    sendBuffer.reserve(lattice.size() * 3);

    for (int y = lattice.height() - 1; y >= 0; y--) {
        for (int x = 0; x < lattice.width(); x++) {
            auto color = lattice.getColor({x, y}).convertToRGB();
            sendBuffer.emplace_back(color.red, color.green, color.blue);
        }
    }

    auto axiomology = Paradigm::getInstance().getAxiomology();
    auto brightness = impresarioUtils::Unwrap::Axiomology(*axiomology)->brightness();
    auto builder = std::make_unique<flatbuffers::FlatBufferBuilder>();
    auto glimpse = builder->CreateVectorOfStructs(sendBuffer);
    auto luminary = ImpresarioSerialization::CreateGlimpse(*builder, brightness, glimpse);
    builder->Finish(luminary);

    socket->sendParcel(ImpresarioSerialization::Identifier::glimpse, *builder);
}

int PalantirVantage::getRefreshRate() {
    return tickInterval;
}

}
