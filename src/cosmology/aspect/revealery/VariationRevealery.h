#ifndef COSMOGRAPHER_VARIATIONREVEALERY_H
#define COSMOGRAPHER_VARIATIONREVEALERY_H

#include "Revealery.h"

namespace cosmographer {

class VariationRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override;
};

}

#endif //COSMOGRAPHER_VARIATIONREVEALERY_H
