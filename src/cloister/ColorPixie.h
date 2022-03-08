#ifndef COSMOGRAPHER_COLORPIXIE_H
#define COSMOGRAPHER_COLORPIXIE_H

#include "CloisterCommunity.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class ColorPixie : public Fellow<CloisterCommunity> {
public:
    HSLColor hueJitter(HSLColor color);

    HSLColor gradiate(
            HSLColor initialColor,
            HSLColor finalColor,
            float amount
    );
};

}

#endif //COSMOGRAPHER_COLORPIXIE_H
