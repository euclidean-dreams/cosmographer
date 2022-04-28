#ifndef COSMOGRAPHER_TRIANGLEREVEALERY_H
#define COSMOGRAPHER_TRIANGLEREVEALERY_H

#include "Revealery.h"
#include "oddments/SimpleMovingAverage.h"

namespace cosmographer {

class TriangleRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override;
};

}

#endif //COSMOGRAPHER_TRIANGLEREVEALERY_H
