#include "LuciferonVantage.h"

namespace cosmographer {

LuciferonVantage::LuciferonVantage(std::unique_ptr<impresarioUtils::NetworkSocket> socket0,
                                   std::unique_ptr<impresarioUtils::NetworkSocket> socket1,
                                   std::unique_ptr<impresarioUtils::NetworkSocket> socket2,
                                   std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter)
        : socket0{move(socket0)},
          socket1{move(socket1)},
          socket2{move(socket2)},
          axiomologyArbiter{move(axiomologyArbiter)},
          tickInterval{LUCIFERON_TICK_INTERVAL} {

}

void LuciferonVantage::send(const Lattice &lattice) {
    auto axiomologyParcel = axiomologyArbiter->take();
    auto rawBrightness = 0.5;
    if (axiomologyParcel != nullptr) {
        auto axioms = impresarioUtils::Unwrap::Axiomology(*axiomologyParcel)->axioms();
        if (axioms->size() > 0) {
            rawBrightness = axioms->Get(0);
        }
    }
    auto brightness = rawBrightness * 255;

    std::vector<ImpresarioSerialization::Color> sendBuffer{};
    sendBuffer.reserve(lattice.size());
    for (int x = 0; x < 20; x++) {
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
    auto glimpse = ImpresarioSerialization::CreateGlimpse(*builder, static_cast<uint8_t>(brightness), colors);
    builder->Finish(glimpse);

    socket0->sendParcel(ImpresarioSerialization::Identifier::glimpse, *builder);

    std::vector<ImpresarioSerialization::Color> sendBuffer1{};
    sendBuffer1.reserve(lattice.size());
    for (int x = 20; x < 40; x++) {
        if (x % 2 == 0) {
            for (int y = 0; y < lattice.height(); y++) {
                auto color = lattice.getColor({x, y}).convertToRGB();
                sendBuffer1.emplace_back(color.red, color.green, color.blue);
            }
        } else {
            for (int y = lattice.height() - 1; y >= 0; y--) {
                auto color = lattice.getColor({x, y}).convertToRGB();
                sendBuffer1.emplace_back(color.red, color.green, color.blue);
            }
        }
    }

    builder = std::make_unique<flatbuffers::FlatBufferBuilder>();
    colors = builder->CreateVectorOfStructs(sendBuffer1);
    glimpse = ImpresarioSerialization::CreateGlimpse(*builder, static_cast<uint8_t>(brightness), colors);
    builder->Finish(glimpse);

    socket1->sendParcel(ImpresarioSerialization::Identifier::glimpse, *builder);

    std::vector<ImpresarioSerialization::Color> sendBuffer2{};
    sendBuffer2.reserve(lattice.size());
    for (int x = 40; x < 60; x++) {
        if (x % 2 == 0) {
            for (int y = 0; y < lattice.height(); y++) {
                auto color = lattice.getColor({x, y}).convertToRGB();
                sendBuffer2.emplace_back(color.red, color.green, color.blue);
            }
        } else {
            for (int y = lattice.height() - 1; y >= 0; y--) {
                auto color = lattice.getColor({x, y}).convertToRGB();
                sendBuffer2.emplace_back(color.red, color.green, color.blue);
            }
        }
    }

    builder = std::make_unique<flatbuffers::FlatBufferBuilder>();
    colors = builder->CreateVectorOfStructs(sendBuffer2);
    glimpse = ImpresarioSerialization::CreateGlimpse(*builder, static_cast<uint8_t>(brightness), colors);
    builder->Finish(glimpse);

    socket2->sendParcel(ImpresarioSerialization::Identifier::glimpse, *builder);
}

int LuciferonVantage::getRefreshRate() {
    return tickInterval;
}

}
