#include "Illuminable.h"

namespace cosmographer {

Illuminable::Illuminable(HSLColor soulColor)
        : Illuminable{{0, 0}, soulColor} {

}

Illuminable::Illuminable(Coordinate origin, HSLColor soulColor)
        : origin{origin},
          soulColor{soulColor} {

}

}
