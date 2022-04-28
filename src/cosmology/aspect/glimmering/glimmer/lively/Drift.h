#ifndef COSMOGRAPHER_DRIFT_H
#define COSMOGRAPHER_DRIFT_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Drift : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    float inclinationOffset;

    Drift(
            GlimmerSoul *glimmerSoul,
            float inclinationOffset
    ) :
            glimmerSoul{glimmerSoul},
            inclinationOffset{inclinationOffset} {

    }

    void live() override {
        auto pole = 0;
        auto direction = inclinationOffset * 2 * M_PI + pole;
        auto distance = MOVEMENT_AXIOM * CONSTANTS->maxDriftDistance;
        glimmerSoul->locus = CLOISTER->cartographer->shiftPoint(glimmerSoul->locus, distance, direction);
        if (!CLOISTER->cartographer->isValid(glimmerSoul->locus)) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_DRIFT_H
