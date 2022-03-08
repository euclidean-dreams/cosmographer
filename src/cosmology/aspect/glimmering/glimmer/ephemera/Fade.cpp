#include "Fade.h"

namespace cosmographer {

Fade::Fade(
        HSLColor initialColor
) :
        initialColor{initialColor} {

}

void Fade::live() {
    auto fadeIncrement = EPHEMERA_AXIOM_2 / 20;
    auto fade = fadeIncrement * community->age;
    community->color = CLOISTER->colorPixie->gradiate(
            initialColor,
            PARADIGM->latticeInitialColor,
            fade
    );
}

}
