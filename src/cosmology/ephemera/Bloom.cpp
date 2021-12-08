#include "Bloom.h"

namespace cosmographer {

Bloom::Bloom(Coordinate origin, HSLColor color)
        : origin{origin},
          innerColor{color} {

}

void Bloom::live(Lattice &lattice) {
    auto radius = 5;
    if (radius > 5) {
        radius = 5;
    }
    Circle circle{origin, innerColor.darken(age * 3), radius};
    circle.illuminate(lattice);
}

bool Bloom::isDead() {
    return age > 20;
}

}
