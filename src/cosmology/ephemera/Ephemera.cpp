#include "Ephemera.h"

namespace cosmographer {

Ephemera::Ephemera(HSLColor soulColor)
        : Ephemera{{0, 0}, soulColor} {

}

Ephemera::Ephemera(Coordinate origin, HSLColor soulColor)
        : origin{origin},
          soulColor{soulColor},
          age{0} {

}

void Ephemera::incrementAge() {
    age++;
}

Coordinate Ephemera::getOrigin() {
    return origin;
}

}
