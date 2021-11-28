#include "PalantirVantage.h"

namespace cosmographer {

PalantirVantage::PalantirVantage(std::shared_ptr<LatticeArbiter> latticeArbiter,
                                 std::unique_ptr<impresarioUtils::NetworkSocket> socket)
        : latticeArbiter{move(latticeArbiter)},
          socket{move(socket)} {

}

void PalantirVantage::activate() {
    auto lattice = latticeArbiter->getLattice();
    std::vector<ImpresarioSerialization::Color> sendBuffer{};
    sendBuffer.reserve(lattice->size() * 3);

    for (int y = lattice->height() - 1; y >= 0; y--) {
        for (int x = 0; x < lattice->width(); x++) {
            auto color = lattice->getColor({x, y}).convertToRGB();
            sendBuffer.emplace_back(color.red, color.green, color.blue);
        }
    }

    auto builder = std::make_unique<flatbuffers::FlatBufferBuilder>();
    auto glimpse = builder->CreateVectorOfStructs(sendBuffer);
    auto luminary = ImpresarioSerialization::CreateLuminary(*builder, glimpse);
    builder->Finish(luminary);

    socket->sendSerializedData(ImpresarioSerialization::Identifier::luminary, *builder);
}

uint64_t PalantirVantage::getTickInterval() {
    return PALANTIR_REFRESH_RATE;
}

bool PalantirVantage::finished() {
    return false;
}
}
