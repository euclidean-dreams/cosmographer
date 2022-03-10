#ifndef COSMOGRAPHER_CARTOGRAPHER_H
#define COSMOGRAPHER_CARTOGRAPHER_H

#include "CloisterCommunity.h"
#include "primitive/Loci.h"

namespace cosmographer {

class Cartographer : public Fellow<CloisterCommunity> {
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
