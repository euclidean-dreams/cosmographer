#ifndef COSMOGRAPHER_REVEALERY_H
#define COSMOGRAPHER_REVEALERY_H

#include "cosmology/aspect/AspectCommunity.h"
#include "cosmology/aspect/glimmering/Glimmering.h"
#include "cosmology/aspect/mesh/lumion/Lumion.h"

namespace cosmographer {

class Revealery : public Fellow<AspectCommunity> {
protected:
    float calculateBaseSize(float excitationMagnitude) {
        return (CONSTANTS->latticeWidth * CONSTANTS->latticeHeight) / 500
               * excitationMagnitude * SIZE_AXIOM + 1;
    }

public:
    virtual void reveal(
            LumionExcitation excitation
    ) = 0;

    virtual void experienceSignal(Signal &signal) {};
};

}

#endif //COSMOGRAPHER_REVEALERY_H
