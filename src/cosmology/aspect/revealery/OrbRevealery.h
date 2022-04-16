#ifndef COSMOGRAPHER_ORBREVEALERY_H
#define COSMOGRAPHER_ORBREVEALERY_H

#include "Revealery.h"

namespace cosmographer {

class OrbRevealery : public Revealery {
public:
    int currentShape;
    float currentInclination;
    float previousEnergy;

    OrbRevealery(

    );

    void experienceSignal(Signal &signal) override;

    void reveal(
            LumionExcitation excitation
    ) override;
};

}

#endif //COSMOGRAPHER_ORBREVEALERY_H