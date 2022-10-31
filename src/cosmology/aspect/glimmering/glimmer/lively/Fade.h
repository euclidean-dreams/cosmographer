#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"
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
        glimmerSoul->color.desaturate(2 * EXHAUSTION_AXIOM);
        if (glimmerSoul->color.saturation <= 0) {
            glimmerSoul->alive = false;
        }
        glimmerSoul->color.darken(5 * EXHAUSTION_AXIOM);
        if (glimmerSoul->color.lightness <= 0) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_FADE_H
