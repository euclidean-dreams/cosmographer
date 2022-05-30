#ifndef COSMOGRAPHER_COLORPIXIE_H
#define COSMOGRAPHER_COLORPIXIE_H

#include "primitive/color/HSLColor.h"

namespace cosmographer {

class ColorPixie {
public:
    HSLColor gradiate(
            HSLColor initialColor,
            HSLColor finalColor,
            float amount
    );
};

}

#endif //COSMOGRAPHER_COLORPIXIE_H
