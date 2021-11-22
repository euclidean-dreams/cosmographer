#include "Coordinate.h"

namespace cosmographer {

Coordinate::Coordinate()
        : Coordinate(0, 0) {

}

Coordinate::Coordinate(int x, int y)
        : x{x},
          y{y} {

}

}
