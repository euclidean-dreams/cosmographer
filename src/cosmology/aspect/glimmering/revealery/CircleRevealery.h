#ifndef COSMOGRAPHER_CIRCLEREVEALERY_H
#define COSMOGRAPHER_CIRCLEREVEALERY_H

#include "Revealery.h"

namespace cosmographer {

class CircleRevealery : public Revealery {
public:
    void reveal(
            LumionExcitation excitation
    ) override;
};

}

#endif //COSMOGRAPHER_CIRCLEREVEALERY_H
