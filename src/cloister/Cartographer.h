#ifndef COSMOGRAPHER_CARTOGRAPHER_H
#define COSMOGRAPHER_CARTOGRAPHER_H

#include "primitive/Loci.h"

namespace cosmographer {

class Cartographer {
public:
    Point verticalWrap(int index);

    int verticalUnwrap(Point point);

    bool isValid(Point point);

    Point shiftPoint(
            Point point,
            float distance,
            float direction
    );
};

}

#endif //COSMOGRAPHER_CARTOGRAPHER_H
