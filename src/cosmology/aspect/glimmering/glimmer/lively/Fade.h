#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Fade : public Lively {
public:
    GlimmerCommunity *glimmerCommunity;
    HSLColor initialColor;
    HSLColor finalColor;
    float lifespan;

    Fade(
            GlimmerCommunity *glimmerCommunity,
            HSLColor initialColor,
            HSLColor finalColor,
            float lifespan
    ) :
            glimmerCommunity{glimmerCommunity},
            initialColor{initialColor},
            finalColor{finalColor},
            lifespan{lifespan} {

    }

    void live() override {
        float fade = glimmerCommunity->age / lifespan;
        glimmerCommunity->color = glimmerCommunity->paradigm->cloister->colorPixie->gradiate(
                initialColor,
                finalColor,
                fade
        );
    }
};

}

#endif //COSMOGRAPHER_FADE_H
