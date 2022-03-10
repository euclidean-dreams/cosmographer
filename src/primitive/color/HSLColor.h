#ifndef COSMOGRAPHER_HSLCOLOR_H
#define COSMOGRAPHER_HSLCOLOR_H

#include "framework/Libs.h"
#include "framework/Macros.h"
#include "RGBColor.h"

namespace cosmographer {

constexpr int HSL_HUE_MAX = 360;

class HSLColor {
public:
    int hue;
    int saturation;
    int lightness;

    HSLColor();

    HSLColor(
            int hue,
            int saturation,
            int lightness
    );

    HSLColor(
            float hue,
            int saturation,
            int lightness
    );

    bool operator==(HSLColor &other) const;

    bool operator!=(HSLColor &other) const;

    void lighten(int amount);

    void darken(int amount);

    RGBColor convertToRGB() const;
};

}

#endif //COSMOGRAPHER_HSLCOLOR_H
