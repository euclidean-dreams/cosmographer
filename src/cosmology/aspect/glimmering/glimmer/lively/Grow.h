#ifndef COSMOGRAPHER_GROW_H
#define COSMOGRAPHER_GROW_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Grow : public Lively {
public:
    GlimmerSoul *glimmerSoul;

    Grow(
            GlimmerSoul *glimmerSoul
    ) :
            glimmerSoul{glimmerSoul} {}

    void live() override {
//        int rate = 10 - paradigm->axioms[5] * 10;
//        if (rate == 0) {
//            rate = 1;
//        }
//        if (glimmerSoul->age % rate == 0) {
//            glimmerSoul->size++;
//        }
    }
};

}

#endif //COSMOGRAPHER_GROW_H
