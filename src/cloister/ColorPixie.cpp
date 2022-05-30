#include "ColorPixie.h"

namespace cosmographer {

HSLColor ColorPixie::gradiate(
        HSLColor initialColor,
        HSLColor finalColor,
        float amount
) {
    if (amount >= 1) {
        return finalColor;
    }
    auto hueDifference = finalColor.hue - initialColor.hue;
    auto hueDelta = hueDifference * amount;
    auto saturationDifference = finalColor.saturation - initialColor.saturation;
    auto saturationDelta = saturationDifference * amount;
    auto lightnessDifference = finalColor.lightness - initialColor.lightness;
    auto lightnessDelta = lightnessDifference * amount;
    return HSLColor{
            cast(int, initialColor.hue + hueDelta),
            cast(int, initialColor.saturation + saturationDelta),
            cast(int, initialColor.lightness + lightnessDelta),
    };
}

}
