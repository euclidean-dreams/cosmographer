#include "PalantirVantage.h"

namespace cosmographer {

PalantirVantage::PalantirVantage(std::unique_ptr<impresarioUtils::NetworkSocket> socket)
        : socket{move(socket)} {

}

void PalantirVantage::send(const Lattice &lattice) {
    auto rawBrightness = AXIOMOLOGY.getBrightness();
    auto brightness = rawBrightness * 255;

    std::vector<ImpresarioSerialization::Color> sendBuffer{};
    sendBuffer.reserve(lattice.size() * 3);
    for (int y = lattice.height() - 1; y >= 0; y--) {
        for (int x = 0; x < lattice.width(); x++) {
            auto color = lattice.getColor({x, y}).convertToRGB();
            sendBuffer.emplace_back(color.red, color.green, color.blue);
        }
    }

    auto builder = std::make_unique<flatbuffers::FlatBufferBuilder>();
    auto colors = builder->CreateVectorOfStructs(sendBuffer);
    auto glimpse = ImpresarioSerialization::CreateGlimpse(*builder, static_cast<uint8_t>(brightness), colors);
    builder->Finish(glimpse);

    socket->sendParcel(ImpresarioSerialization::Identifier::glimpse, *builder);
}

}
