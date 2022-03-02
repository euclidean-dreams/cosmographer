#ifndef COSMOGRAPHER_COLORPIXIE_H
#define COSMOGRAPHER_COLORPIXIE_H

#include "default.h"
#include "cloister/chromatica/ChromaticaCommunity.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class ColorPixie : public Fellow<ChromaticaCommunity> {
public:
    HSLColor hueJitter(HSLColor color);
};

}

#endif //COSMOGRAPHER_COLORPIXIE_H
