#ifndef COSMOGRAPHER_HSLCOLOR_H
#define COSMOGRAPHER_HSLCOLOR_H

#include <cstdint>
#include <cmath>
#include <sstream>
#include <ImpresarioUtils.h>
#include "gizmo/color/RGBColor.h"

namespace cosmographer {

constexpr int HSL_HUE_MAX = 360;

class HSLColor {
private:
    uint32_t hue;
    uint8_t saturation;
    uint8_t lightness;

public:
    HSLColor(int hue, int saturation, int lightness);

    uint32_t getHue() const;

    uint8_t getSaturation() const;

    uint8_t getLightness() const;

    HSLColor newHue(int newHue) const;

    HSLColor newSaturation(int newSaturation) const;

    HSLColor newLightness(int newLightness) const;

    HSLColor lighten(int amount) const;

    HSLColor darken(int amount) const;

    RGBColor convertToRGB() const;
};

}

#endif //COSMOGRAPHER_HSLCOLOR_H
