#include "PalantirVantage.h"

namespace cosmographer {

PalantirVantage::PalantirVantage(
        up<NetworkSocket> socket
) :
        socket{mv(socket)} {
    LOGGER->info("initializing palantir vantage");
}

void PalantirVantage::send(const Lattice &lattice) {
    vec<Color> sendBuffer{};
    sendBuffer.reserve(lattice.size() * 3);
    for (int y = lattice.height - 1; y >= 0; y--) {
        for (int x = 0; x < lattice.width; x++) {
            auto color = lattice.getColor(x, y).convertToRGB();
            sendBuffer.emplace_back(color.red, color.green, color.blue);
        }
    }

    auto builder = mkup<flatbuffers::FlatBufferBuilder>();
    auto colors = builder->CreateVectorOfStructs(sendBuffer);
    auto glimpse = CreateGlimpse(*builder, 100, colors);
    builder->Finish(glimpse);

    socket->sendParcel(Identifier::glimpse, *builder);
}

}
