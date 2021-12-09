#ifndef COSMOGRAPHER_COORDINATETRANSFORMER_H
#define COSMOGRAPHER_COORDINATETRANSFORMER_H

#include "gizmo/paradigm/Paradigm.h"
#include "gizmo/Coordinate.h"

namespace cosmographer {

class CoordinateTransformer {
public:
    static Coordinate verticalWrap(int index);

    static int verticalUnwrap(Coordinate coordinate);
};

}

#endif //COSMOGRAPHER_COORDINATETRANSFORMER_H
