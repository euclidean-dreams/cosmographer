#include "Cosmology.h"

namespace cosmographer {

Cosmology::Cosmology()
        : aspect{std::make_unique<SeedAspect>()},
          tick{0} {

}

std::unique_ptr<Lattice> Cosmology::observe() {
    auto lattice = aspect->manifest(tick);
    tick++;
    return lattice;
}

void Cosmology::alter(const impresarioUtils::Packet &packet) {
    aspect->alter(packet);
}

}
