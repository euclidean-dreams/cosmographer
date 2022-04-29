#ifndef COSMOGRAPHER_EXPLORERPALETTE_H
#define COSMOGRAPHER_EXPLORERPALETTE_H

#include "Palette.h"

namespace cosmographer {

class ExplorerPalette : public Palette {
private:
    float hue;
    float saturation;
    float lightness;

public:
    ExplorerPalette(
    );

    HSLColor getColor() override;

    void experienceEssentia() override;
};

}

#endif //COSMOGRAPHER_EXPLORERPALETTE_H
