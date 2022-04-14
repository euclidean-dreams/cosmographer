#ifndef COSMOGRAPHER_DRIFT_H
#define COSMOGRAPHER_DRIFT_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Drift : public Lively {
public:
    GlimmerCommunity *glimmerCommunity;
    float inclinationOffset;

    Drift(
            GlimmerCommunity *glimmerCommunity,
            float inclinationOffset
    ) :
            glimmerCommunity{glimmerCommunity},
            inclinationOffset{inclinationOffset} {

    }

    void live() override {
        auto pole = glimmerCommunity->paradigm->axioms[5] * 2 * M_PI;
        auto direction = inclinationOffset * 2 * M_PI + pole;
        auto distance = glimmerCommunity->paradigm->axioms[6] *
                        glimmerCommunity->paradigm->cloister->constants->maxDriftDistance;
        glimmerCommunity->locus = glimmerCommunity->paradigm->cloister->cartographer->shiftPoint(
                glimmerCommunity->locus, distance, direction);
    }
};

}

#endif //COSMOGRAPHER_DRIFT_H
