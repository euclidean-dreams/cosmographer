#include "Bloom.h"

namespace cosmographer {

Bloom::Bloom(Coordinate origin, HSLColor soulColor, float scale)
        : Ephemera{origin, soulColor},
          scale{scale} {

}

void Bloom::live(Lattice &lattice) {
    auto axiomology = AXIOMOLOGY;
    int radius = age / (5.1 - 5 * axiomology.getWildcard(0));
    int maxRadius = 20 * axiomology.getWildcard(2) * scale;
    if (radius > maxRadius) {
        radius = maxRadius;
    }
    Circle circle{origin, soulColor, radius};
    circle.illuminate(lattice);
    soulColor = soulColor.darken(age / (axiomology.getWildcard(1) * 50));
}

bool Bloom::isDead() {
    return soulColor.getLightness() == 0;
}

}
