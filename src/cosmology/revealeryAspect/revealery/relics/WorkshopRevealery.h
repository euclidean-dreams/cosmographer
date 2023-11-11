#ifndef COSMOGRAPHER_WORKSHOPREVEALERY_H
#define COSMOGRAPHER_WORKSHOPREVEALERY_H

#include "cosmology/revealeryAspect/revealery/Revealery.h"
#include "oddments/SignalAverage.h"

namespace cosmographer {

class WorkshopRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override;
};

}

#endif //COSMOGRAPHER_WORKSHOPREVEALERY_H
