#ifndef COSMOGRAPHER_SINGLECOLORPALETTE_H
#define COSMOGRAPHER_SINGLECOLORPALETTE_H

#include "gizmo/color/palette/Palette.h"

namespace cosmographer {

class SingleColorPalette : public Palette {
public:
    HSLColor getColor(int index) override;
};

}

#endif //COSMOGRAPHER_SINGLECOLORPALETTE_H
