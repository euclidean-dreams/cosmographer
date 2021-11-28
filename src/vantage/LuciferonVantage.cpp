#include "LuciferonVantage.h"

namespace cosmographer {

LuciferonVantage::LuciferonVantage(std::shared_ptr<LatticeArbiter> latticeArbiter,
                                   std::unique_ptr<impresarioUtils::NetworkSocket> socket)
        : latticeArbiter{move(latticeArbiter)},
          socket{move(socket)} {

}

void LuciferonVantage::activate() {
    auto lattice = latticeArbiter->getLattice();
    if(lattice == nullptr) {
        return;
    }
    std::vector<ImpresarioSerialization::Color> sendBuffer{};
    sendBuffer.reserve(lattice->size());
    for (int x = 0; x < lattice->width(); x++) {
        if (x % 2 == 0) {
            for (int y = 0; y < lattice->height(); y++) {
                auto color = lattice->getColor({x, y}).convertToRGB();
                sendBuffer.emplace_back(color.red, color.green, color.blue);
            }
        } else {
            for (int y = lattice->height() - 1; y >= 0; y--) {
                auto color = lattice->getColor({x, y}).convertToRGB();
                sendBuffer.emplace_back(color.red, color.green, color.blue);
            }
        }
    }

    auto builder = std::make_unique<flatbuffers::FlatBufferBuilder>();
    auto glimpse = builder->CreateVectorOfStructs(sendBuffer);
    auto luminary = ImpresarioSerialization::CreateLuminary(*builder, glimpse);
    builder->Finish(luminary);

    socket->sendSerializedData(ImpresarioSerialization::Identifier::luminary, *builder);
}

uint64_t LuciferonVantage::getTickInterval() {
    return LUCIFERON_REFRESH_RATE;
}

bool LuciferonVantage::finished() {
    return false;
}

}
