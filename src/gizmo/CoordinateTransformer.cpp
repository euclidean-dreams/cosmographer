#include <cstdlib>
#include "CoordinateTransformer.h"

namespace cosmographer {

Coordinate CoordinateTransformer::verticalWrap(int index, uint latticeWidth) {
    return {static_cast<int>(index % latticeWidth), static_cast<int>(index / latticeWidth)};
}

}
