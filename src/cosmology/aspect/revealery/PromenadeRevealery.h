#ifndef COSMOGRAPHER_PROMENADEREVEALERY_H
#define COSMOGRAPHER_PROMENADEREVEALERY_H

#include "Revealery.h"
#include "oddments/SignalAverage.h"

namespace cosmographer {

class PromenadeRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override;
};

}
#endif //COSMOGRAPHER_PROMENADEREVEALERY_H
