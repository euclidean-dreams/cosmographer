#include "Fade.h"

namespace cosmographer {

Fade::Fade(
        HSLColor initialColor,
        HSLColor finalColor,
        float lifespan
) :
        initialColor{initialColor},
        finalColor{finalColor},
        lifespan{lifespan} {

}

void Fade::live() {
    float fade = community->age / lifespan;
    community->color = CLOISTER->colorPixie->gradiate(
            initialColor,
            finalColor,
            fade
    );
}

}
