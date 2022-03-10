#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Ephemera.h"

namespace cosmographer {

class Fade : public Ephemera {
public:
    HSLColor initialColor;
    HSLColor finalColor;
    float lifespan;

    Fade(
            HSLColor initialColor,
            HSLColor finalColor,
            float lifespan
    );

    void live() override;
};

}

#endif //COSMOGRAPHER_FADE_H
