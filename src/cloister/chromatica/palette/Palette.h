#ifndef COSMOGRAPHER_PALETTE_H
#define COSMOGRAPHER_PALETTE_H

#include "Default.h"
#include "cloister/chromatica/ChromaticaCommunity.h"
#include "cloister/ColorPixie.h"
#include "primitive/color/HSLColor.h"
#include "oddments/Tidbit.h"

namespace cosmographer {

class Palette : public Fellow<ChromaticaCommunity> {
public:
    virtual HSLColor get_color() = 0;

    virtual void experienceEssentia() {};

    HSLColor jitter(HSLColor color) {
        float colorDeviation = 75 * COLOR_ACCENT_AXIOM;
        float lightnessDeviation = 25 * COLOR_ACCENT_AXIOM;
        return {
                color.hue + randomizer->generate(colorDeviation * 2) - colorDeviation,
                cast(int, color.saturation + randomizer->generate(lightnessDeviation * 2) - lightnessDeviation),
                cast(int, color.lightness + randomizer->generate(lightnessDeviation * 2) - lightnessDeviation)
        };
    }
};

class ExplorerPalette : public Palette {
private:
    float hue;
    float saturation;
    float lightness;

public:
    ExplorerPalette(

    ) :
            hue{cast(float, constants->latticeInitialColor.hue)},
            saturation{100},
            lightness{80} {

    }

    HSLColor get_color() override {
        return {hue, cast(int, saturation), cast(int, lightness)};
    }

    void experienceEssentia() override {
        float variance = COLOR_BASE_AXIOM;
        hue += variance * randomizer->generate(2);

        saturation = COLOR_ACCENT_AXIOM - 0.5;
        saturation = Tidbit::bind(cast(float, saturation + saturation * randomizer->generate(2)), 80.0f, 100.0f);

        lightness = COLOR_ACCENT_AXIOM - 0.5;
        lightness = Tidbit::bind(cast(float, lightness + lightness * randomizer->generate(3)), 70.0f, 100.0f);
    }

};

class GradientPalette : public Palette {
public:
    HSLColor get_color() override {
        return jitter({COLOR_BASE_AXIOM * HSL_HUE_MAX, 100, 50});
    }

};

}

#endif //COSMOGRAPHER_PALETTE_H
