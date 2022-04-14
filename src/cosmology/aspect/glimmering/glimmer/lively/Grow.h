#ifndef COSMOGRAPHER_GROW_H
#define COSMOGRAPHER_GROW_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Grow : public Lively {
public:
    GlimmerCommunity *glimmerCommunity;

    Grow(
            GlimmerCommunity *glimmerCommunity
    ) :
            glimmerCommunity{glimmerCommunity} {}

    void live() override {
        int rate = 10 - glimmerCommunity->paradigm->axioms[5] * 10;
        if (rate == 0) {
            rate = 1;
        }
        if (glimmerCommunity->age % rate == 0) {
            glimmerCommunity->size++;
        }
    }
};

}

#endif //COSMOGRAPHER_GROW_H
