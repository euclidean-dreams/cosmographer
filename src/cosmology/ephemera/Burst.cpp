#include "Burst.h"

namespace cosmographer {

Burst::Burst(Coordinate origin, HSLColor soulColor, float scale)
        : Ephemera{origin, soulColor},
          scale{scale} {

}

void Burst::live(Lattice &lattice) {
    auto axiomology = AXIOMOLOGY;
    int radius = age / (5.1 - 5 * axiomology.getWildcard(0));
    int maxRadius = 20 * axiomology.getWildcard(2) * scale;
    if (radius > maxRadius) {
        radius = maxRadius;
    }
    auto density = axiomology.getWildcard(3) / 32;
    RandomScatter randomScatter{origin, soulColor, radius, density};
    randomScatter.illuminate(lattice);
    soulColor = soulColor.darken(age / (axiomology.getWildcard(1) * 50));

}

bool Burst::isDead() {
    return soulColor.getLightness() == 0;
}
}
