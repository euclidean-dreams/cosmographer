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
        auto direction = pole->pole + inclinationOffset;
        auto distance = MOVEMENT_AXIOM * 3;
        glimmerSoul->locus = cartographer->shiftPoint(glimmerSoul->locus, distance, direction);
        if (!cartographer->isValid(glimmerSoul->locus)) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_DRIFT_H
