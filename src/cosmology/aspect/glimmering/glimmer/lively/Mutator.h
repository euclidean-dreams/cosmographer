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
        glimmerSoul->size += randomizer->generate(sizeDeviation * 2) - sizeDeviation;
        float ageDeviation = 5 * CHAOS_AXIOM;
        glimmerSoul->age += randomizer->generate(ageDeviation * 2) - ageDeviation;
        float locusDeviation = 0.5 * CHAOS_AXIOM;
        glimmerSoul->locus.x += randomizer->generate(locusDeviation * 2) - locusDeviation;
        glimmerSoul->locus.y += randomizer->generate(locusDeviation * 2) - locusDeviation;
        float colorDeviation = 16 * LIGHTNESS_AXIOM;
        glimmerSoul->color = {
                glimmerSoul->color.hue,
                glimmerSoul->color.saturation - randomizer->generate(colorDeviation),
                glimmerSoul->color.lightness - randomizer->generate(colorDeviation)
        };
        if (glimmerSoul->color.lightness <= 0 || glimmerSoul->color.saturation <= 0) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_MUTATOR_H
