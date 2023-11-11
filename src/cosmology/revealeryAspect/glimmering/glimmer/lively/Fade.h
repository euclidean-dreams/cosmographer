#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Lively.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/GlimmerSoul.h"
#include "Lifespan.h"

namespace cosmographer {

class Fade : public Lively {
public:
    GlimmerSoul *glimmerSoul;

    Fade(
            GlimmerSoul *glimmerSoul
    ) :
            glimmerSoul{glimmerSoul} {

    }

    void live() override {
        if (randomizer->generateProportion() < EXHAUSTION_AXIOM * 3) {
            glimmerSoul->color.darken(1);
            if (glimmerSoul->color.lightness <= 0) {
                glimmerSoul->alive = false;
            }
        }
    }
};

}

#endif //COSMOGRAPHER_FADE_H
