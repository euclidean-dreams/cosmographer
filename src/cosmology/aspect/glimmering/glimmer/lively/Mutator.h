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
        float sizeDeviation = 0.1 * CHAOS_AXIOM * SIZE_AXIOM;
        glimmerSoul->size += RANDOM.generate(sizeDeviation * 2) - sizeDeviation;
        float ageDeviation = 5 * CHAOS_AXIOM;
        glimmerSoul->age += RANDOM.generate(ageDeviation * 2) - ageDeviation;
        float locusDeviation = 0.5 * CHAOS_AXIOM;
        glimmerSoul->locus.x += RANDOM.generate(locusDeviation * 2) - locusDeviation;
        glimmerSoul->locus.y += RANDOM.generate(locusDeviation * 2) - locusDeviation;
        float colorDeviation = 5 * HUE_JITTER_AXIOM;
        glimmerSoul->color = {
                glimmerSoul->color.hue + RANDOM.generate(colorDeviation * 2) - colorDeviation,
                cast(int, glimmerSoul->color.saturation + RANDOM.generate(colorDeviation * 2) - colorDeviation),
                cast(int, glimmerSoul->color.lightness + RANDOM.generate(colorDeviation * 2) - colorDeviation)
        };
    }
};

}

#endif //COSMOGRAPHER_MUTATOR_H
