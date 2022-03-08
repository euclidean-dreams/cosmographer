#ifndef COSMOGRAPHER_FADE_H
#define COSMOGRAPHER_FADE_H

#include "Ephemera.h"

namespace cosmographer {

class Fade : public Ephemera {
public:
    HSLColor initialColor;

    Fade(
            HSLColor initialColor
    );

    void live() override;
};

}

#endif //COSMOGRAPHER_FADE_H
