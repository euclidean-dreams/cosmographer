#ifndef COSMOGRAPHER_MUTATOR_H
#define COSMOGRAPHER_MUTATOR_H

#include "Lively.h"
#include "cosmology/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Mutator : public Lively {
public:
    GlimmerSoul *glimmerSoul;

    Mutator(
            GlimmerSoul *glimmerSoul
    ) :
            glimmerSoul{glimmerSoul} {}

    void live() override {
        float locusDeviation = 0.5 * CHAOS_AXIOM;
        glimmerSoul->locus.x += randomizer->generate(locusDeviation * 2) - locusDeviation;
        glimmerSoul->locus.y += randomizer->generate(locusDeviation * 2) - locusDeviation;
//        float lightnessDeviation = 2 * COLOR_ACCENT_AXIOM;
//        glimmerSoul->color = {
//                glimmerSoul->color.hue,
//                cast(int, glimmerSoul->color.saturation),
//                cast(int,
//                     glimmerSoul->color.lightness + randomizer->generate(lightnessDeviation * 2) - lightnessDeviation)
//        };
//        if (glimmerSoul->color.lightness <= 0 || glimmerSoul->color.lightness >= 100 ||
//            glimmerSoul->color.saturation <= 0 || glimmerSoul->color.saturation >= 100) {
//            glimmerSoul->alive = false;
//        }
    }
};

}

#endif //COSMOGRAPHER_MUTATOR_H
