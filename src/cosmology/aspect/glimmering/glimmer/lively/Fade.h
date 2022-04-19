#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Fade : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    HSLColor initialColor;
    HSLColor finalColor;
    float lifespan;

    Fade(
            GlimmerSoul *glimmerSoul,
            HSLColor initialColor,
            HSLColor finalColor,
            float lifespan
    ) :
            glimmerSoul{glimmerSoul},
            initialColor{initialColor},
            finalColor{finalColor},
            lifespan{lifespan} {

    }

    void live() override {
        float fade = glimmerSoul->age / lifespan;
        glimmerSoul->color = paradigm->cloister->colorPixie->gradiate(
                initialColor,
                finalColor,
                fade
        );
        if (glimmerSoul->color == paradigm->cloister->constants->latticeInitialColor) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_FADE_H
