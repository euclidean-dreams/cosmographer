#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Lively.h"
#include "cosmology/glimmering/glimmer/GlimmerSoul.h"
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
        auto fade = EXHAUSTION_AXIOM;
        glimmerSoul->color.desaturate(2 * fade);
        if (glimmerSoul->color.saturation <= 0) {
            glimmerSoul->alive = false;
        }
        glimmerSoul->color.lighten(2 * fade);
        if (glimmerSoul->color.lightness >= 100) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_FADE_H
