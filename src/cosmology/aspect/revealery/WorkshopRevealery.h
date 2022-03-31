#ifndef COSMOGRAPHER_WORKSHOPREVEALERY_H
#define COSMOGRAPHER_WORKSHOPREVEALERY_H

#include "Revealery.h"
#include "squire/SimpleMovingAverage.h"

namespace cosmographer {

class WorkshopRevealery : public Revealery {
public:
    SimpleMovingAverage energyAverage;

    WorkshopRevealery();

    void reveal(
            LumionExcitation excitation
    ) override;
};

}

#endif //COSMOGRAPHER_WORKSHOPREVEALERY_H
