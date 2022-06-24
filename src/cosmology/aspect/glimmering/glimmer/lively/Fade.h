#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"
#include "Lifespan.h"

namespace cosmographer {

class Fade : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    HSLColor fadeColor;

    Fade(
            GlimmerSoul *glimmerSoul,
            HSLColor fadeColor
    ) :
            glimmerSoul{glimmerSoul},
            fadeColor{fadeColor} {

    }

    void live() override {
        float fade = glimmerSoul->age / 5;
        glimmerSoul->color = colorPixie->gradiate(
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
