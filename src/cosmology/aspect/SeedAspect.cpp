#include "SeedAspect.h"

namespace cosmographer {

SeedAspect::SeedAspect()
        : displaySignal{nullptr} {

}

std::unique_ptr<Lattice> SeedAspect::manifest(int tick) {
    auto height = Config::getInstance().getKeyholeHeight();
    auto width = Config::getInstance().getKeyholeWidth() * Config::getInstance().getKeyholeCount();
    auto lattice = std::make_unique<Lattice>(width, height);
    if (displaySignal != nullptr) {
        for (int y = 0; y < lattice->height(); y++) {
            for (int x = 0; x < lattice->width(); x++) {
                uint32_t hue = tick / 10 % HSL_HUE_MAX;
                auto displaySignalIndex = y * lattice->width() + x;
                auto lightness = (int) (*displaySignal)[displaySignalIndex] * 100;
                if (lightness > 100) {
                    lightness = 100;
                }
                lattice->setColor({x, y}, {hue, 100, static_cast<uint8_t>(lightness)});
            }
        }
    }

    return lattice;
//    auto microcosm = std::make_unique<Microcosm>();
//    auto &lattice = microcosm->getLattice();
//    if (tick % 1 == 0) {
//        y++;
//        if (y >= lattice.height()) {
//            y = 0;
//            x++;
//            if (x >= lattice.width()) {
//                x = 0;
//            }
//        }
//    }
////    for (int x = 0; x < lattice.width(); x++) {
////        for (int y = 0; y < lattice.height(); y++) {
////            lattice.setColor({x, y}, {250, 100, static_cast<uint8_t>(x * y /lattice.height())});
////        }
////    }
//    lattice.setColor({x, y}, {250, 100, 1});
//    return microcosm;
}

void SeedAspect::alter(const impresarioUtils::Packet &packet) {
    if (packet.getIdentifier() == ImpresarioSerialization::Identifier::displaySignal) {
        auto rawDisplaySignal = packet.getDisplaySignal();
        auto samples = rawDisplaySignal->samples();
        displaySignal = std::make_unique<std::vector<float>>();
        displaySignal->reserve(samples->size());
        for (int index = 0; index < samples->size(); index++) {
            auto sample = samples->Get(index);
            if (sample < 0) {
                sample = 0;
            }

            // due to mel filterbank overflow, that last triangular filter catches everything above it
            // accommodate for crazy large last sample - this will go once those ridiculous triangular filters are changed
            if (index == samples->size() - 1) {
                sample /= 100;
            }

            // add sample
            displaySignal->push_back(sample);
        }
    }

}

}
