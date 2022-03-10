#include "Paraboloid.h"

namespace cosmographer {

Paraboloid::Paraboloid(
        int power
) :
        power{power} {

}

void Paraboloid::illuminate(
        Lattice &lattice
) {
    auto timelingBound = community->size;
    for (float timeling = 0; timeling < timelingBound; timeling += CONSTANTS->parametroTimelingIncrement) {
        auto x = timeling + community->locus.x;
        auto y = pow(timeling, power) + community->locus.y;
        if (lattice.isValid(x, y)) {
            lattice.setColor(x, y, community->color);
        }
    }

}

}
