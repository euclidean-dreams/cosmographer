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
    HSLColor fadeColor;

    Fade(
            GlimmerSoul *glimmerSoul,
            Lifespan *lifespan,
            HSLColor fadeColor
    ) :
            glimmerSoul{glimmerSoul},
            lifespan{lifespan},
            fadeColor{fadeColor} {

    }

    void live() override {
        float fade = glimmerSoul->age / lifespan->value;
        glimmerSoul->color = CLOISTER->colorPixie->gradiate(
                glimmerSoul->color,
                fadeColor,
                fade
        );
        if (glimmerSoul->color == fadeColor) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_FADE_H
