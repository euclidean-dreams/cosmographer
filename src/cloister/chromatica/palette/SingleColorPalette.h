#ifndef COSMOGRAPHER_SINGLECOLORPALETTE_H
#define COSMOGRAPHER_SINGLECOLORPALETTE_H

#include "Palette.h"

namespace cosmographer {

class SingleColorPalette : public Palette {
public:
    HSLColor getColor() override {
        return community->colorPixie->hueJitter({cast(int, PALETTE_AXIOM_0 * HSL_HUE_MAX), 100, 50});
    }
};

}

#endif //COSMOGRAPHER_SINGLECOLORPALETTE_H
