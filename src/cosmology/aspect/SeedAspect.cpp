#include "SeedAspect.h"

namespace cosmographer {

SeedAspect::SeedAspect()
        : x{0},
          y{0} {

}

std::unique_ptr<Lattice> SeedAspect::manifest(int tick) {
    auto height = Config::getInstance().getKeyholeHeight();
    auto width = Config::getInstance().getKeyholeWidth() * Config::getInstance().getKeyholeCount();
    auto lattice = std::make_unique<Lattice>(width, height);

    for(int i = 0; i < 20; i++) {
        lattice->setColor({i, i}, {250, 100, 50});
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

}

}
