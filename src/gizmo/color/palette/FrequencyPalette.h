#ifndef COSMOGRAPHER_FREQUENCYPALETTE_H
#define COSMOGRAPHER_FREQUENCYPALETTE_H

#include "gizmo/color/palette/Palette.h"

namespace cosmographer {

class FrequencyPalette: public Palette {
public:
    HSLColor getColor(int index) override;
};

}

#endif //COSMOGRAPHER_FREQUENCYPALETTE_H
