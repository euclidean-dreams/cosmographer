#include "Bloom.h"

namespace cosmographer {

Bloom::Bloom(Coordinate origin, HSLColor soulColor)
        : Ephemera{origin, soulColor} {

}

void Bloom::live(Lattice &lattice) {
    int radius = age / (5.1 - AXIOMOLOGY->getWildcard(0) * 5);
    int maxRadius = AXIOMOLOGY->getWildcard(1) * 10;
    if (radius > maxRadius) {
        radius = maxRadius;
    }
    soulColor = soulColor.darken(age / (AXIOMOLOGY->getWildcard(2) * 20));
    Circle circle{origin, soulColor, radius};
    circle.illuminate(lattice);
}

bool Bloom::isDead() {
    return soulColor.getLightness() == 0;
}

}
