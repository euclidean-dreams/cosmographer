#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"
#include "Lifespan.h"

namespace cosmographer {

class Fade : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    Lifespan *lifespan;

    Fade(
            GlimmerSoul *glimmerSoul,
            Lifespan *lifespan
    ) :
            glimmerSoul{glimmerSoul},
            lifespan{lifespan} {

    }

    void live() override {
        float fade = glimmerSoul->age / lifespan->value;
        glimmerSoul->color = CLOISTER->colorPixie->gradiate(
                glimmerSoul->color,
                CONSTANTS->latticeInitialColor,
                fade
        );
        if (glimmerSoul->color == CONSTANTS->latticeInitialColor) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_FADE_H
