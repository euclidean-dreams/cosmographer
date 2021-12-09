#include "CoordinateTransformer.h"

namespace cosmographer {

Coordinate CoordinateTransformer::verticalWrap(int index) {
    return {static_cast<int>(index % PARADIGM.getLatticeWidth()), static_cast<int>(std::floor(index / PARADIGM.getLatticeWidth()))};
}

int CoordinateTransformer::verticalUnwrap(Coordinate coordinate) {
    return coordinate.y * static_cast<int>(PARADIGM.getLatticeWidth()) + coordinate.x;
}

}
