#ifndef COSMOGRAPHER_MUTATOR_H
#define COSMOGRAPHER_MUTATOR_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Mutator : public Lively {
public:
    GlimmerSoul *glimmerSoul;

    Mutator(
            GlimmerSoul *glimmerSoul
    ) :
            glimmerSoul{glimmerSoul} {}

    void live() override {
        float sizeDeviation = 50 * MUTATION_AXIOM * SIZE_AXIOM;
        glimmerSoul->size += RANDOM.generate(sizeDeviation * 2) - sizeDeviation;
//        glimmerSoul->color = CLOISTER->colorPixie->hueJitter(glimmerSoul->color, 50 * MUTATION_AXIOM);
//        glimmerSoul->size += RANDOM.generate(max) - max / 2;
    }
};

}

#endif //COSMOGRAPHER_MUTATOR_H
