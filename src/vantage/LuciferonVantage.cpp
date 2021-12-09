#include "LuciferonVantage.h"

namespace cosmographer {

LuciferonVantage::LuciferonVantage(std::unique_ptr<impresarioUtils::NetworkSocket> socket)
        : socket{move(socket)},
          tickInterval{LUCIFERON_TICK_INTERVAL} {

}

void LuciferonVantage::send(const Lattice &lattice) {
    std::vector<ImpresarioSerialization::Color> sendBuffer{};
    sendBuffer.reserve(lattice.size());
    for (int x = 0; x < lattice.width(); x++) {
        if (x % 2 == 0) {
            for (int y = 0; y < lattice.height(); y++) {
                auto color = lattice.getColor({x, y}).convertToRGB();
                sendBuffer.emplace_back(color.red, color.green, color.blue);
            }
        } else {
            for (int y = lattice.height() - 1; y >= 0; y--) {
                auto color = lattice.getColor({x, y}).convertToRGB();
                sendBuffer.emplace_back(color.red, color.green, color.blue);
            }
        }
    }

    auto builder = std::make_unique<flatbuffers::FlatBufferBuilder>();
    auto colors = builder->CreateVectorOfStructs(sendBuffer);
    auto brightness = AXIOMOLOGY->getBrightness() * 255;
    auto glimpse = ImpresarioSerialization::CreateGlimpse(*builder, static_cast<uint8_t>(brightness), colors);
    builder->Finish(glimpse);

    socket->sendParcel(ImpresarioSerialization::Identifier::glimpse, *builder);
}

int LuciferonVantage::getRefreshRate() {
    return tickInterval;
}

}
