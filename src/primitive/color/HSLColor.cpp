#include "HSLColor.h"

namespace cosmographer {

HSLColor::HSLColor() {
}

HSLColor::HSLColor(
        int hue,
        int saturation,
        int lightness
) {
    if (lightness > 100) {
        lightness = 100;
    } else if (lightness < 0) {
        lightness = 0;
    }
    if (saturation > 100) {
        saturation = 100;
    } else if (saturation < 0) {
        saturation = 0;
    }
    while (hue < 0) {
        hue += HSL_HUE_MAX;
    }
    this->hue = hue % HSL_HUE_MAX;
    this->saturation = saturation;
    this->lightness = lightness;
}

HSLColor::HSLColor(
        float hue,
        int saturation,
        int lightness
) :
        HSLColor(cast(int, hue), saturation, lightness) {

}

void HSLColor::lighten(int amount) {
    lightness += amount;
    if (lightness > 100) {
        lightness = 100;
    }
}

void HSLColor::darken(int amount) {
    lightness -= amount;
    if (lightness > 100) {
        lightness = 100;
    }
}

RGBColor HSLColor::convertToRGB() const {
    auto workingHue = cast(float, hue);
    auto workingSaturation = cast(float, saturation) / 100;
    auto workingLightness = cast(float, lightness) / 100;
    auto hDabba = workingHue / 60.0f;
    auto chroma = (1.0f - std::abs(2.0f * workingLightness - 1.0f)) * workingSaturation;
    auto intermediary = chroma * (1.0f - std::abs(std::fmod(hDabba, 2.0f) - 1.0f));
    auto lightnessAdjustment = workingLightness - chroma / 2.0f;
    float initialRed, initialGreen, initialBlue;
    if (0.0f <= hDabba && hDabba <= 1.0f) {
        initialRed = chroma;
        initialGreen = intermediary;
        initialBlue = 0.0f;
    } else if (1.0f <= hDabba && hDabba <= 2.0f) {
        initialRed = intermediary;
        initialGreen = chroma;
        initialBlue = 0.0f;
    } else if (2.0f <= hDabba && hDabba <= 3.0f) {
        initialRed = 0.0f;
        initialGreen = chroma;
        initialBlue = intermediary;
    } else if (3.0f <= hDabba && hDabba <= 4.0f) {
        initialRed = 0.0f;
        initialGreen = intermediary;
        initialBlue = chroma;
    } else if (4.0f <= hDabba && hDabba <= 5.0f) {
        initialRed = intermediary;
        initialGreen = 0.0f;
        initialBlue = chroma;
    } else {
        initialRed = chroma;
        initialGreen = 0.0f;
        initialBlue = intermediary;
    }
    auto red = cast(uint8_t, std::roundf((initialRed +lightnessAdjustment) * 255));
    auto green = cast(uint8_t, std::roundf((initialGreen +lightnessAdjustment) * 255));
    auto blue = cast(uint8_t, std::roundf((initialBlue +lightnessAdjustment) * 255));
    return RGBColor{red, green, blue};
}

bool HSLColor::operator==(HSLColor &other) const {
    if (
            hue == other.hue &&
            saturation == other.saturation &&
            lightness == other.lightness
            ) {
        return true;
    } else return false;
}

bool HSLColor::operator!=(HSLColor &other) const {
    if (
            hue != other.hue ||
            saturation != other.saturation ||
            lightness != other.lightness
            ) {
        return true;
    } else return false;
}

}
