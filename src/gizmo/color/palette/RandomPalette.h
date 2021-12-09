#ifndef COSMOGRAPHER_RANDOMPALETTE_H
#define COSMOGRAPHER_RANDOMPALETTE_H

#include "gizmo/color/palette/Palette.h"

namespace cosmographer {

class RandomPalette: public Palette {
public:
    HSLColor getColor(int index) override;
};

}

#endif //COSMOGRAPHER_RANDOMPALETTE_H
