#ifndef COSMOGRAPHER_COORDINATETRANSFORMER_H
#define COSMOGRAPHER_COORDINATETRANSFORMER_H

#include "gizmo/Coordinate.h"

namespace cosmographer {

class CoordinateTransformer {
public:
    static Coordinate verticalWrap(int index, uint latticeWidth);
};

}

#endif //COSMOGRAPHER_COORDINATETRANSFORMER_H
