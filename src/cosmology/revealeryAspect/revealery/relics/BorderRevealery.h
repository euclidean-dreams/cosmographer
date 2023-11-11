#ifndef COSMOGRAPHER_BORDERREVEALERY_H
#define COSMOGRAPHER_BORDERREVEALERY_H

#include "cosmology/revealeryAspect/revealery/Revealery.h"
#include "oddments/SignalAverage.h"

namespace cosmographer {

class BorderRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override;
};

}
#endif //COSMOGRAPHER_BORDERREVEALERY_H
