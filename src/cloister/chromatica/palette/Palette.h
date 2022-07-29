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
    virtual HSLColor getColor() = 0;

    virtual void experienceEssentia() {};

    HSLColor jitter(HSLColor color) {
        float colorDeviation = 15 * HUE_JITTER_AXIOM;
        return {
                color.hue + randomizer->generate(colorDeviation * 2) - colorDeviation,
                cast(int, color.saturation + randomizer->generate(colorDeviation * 2) - colorDeviation),
                cast(int, color.lightness + randomizer->generate(colorDeviation * 2) - colorDeviation)
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

    HSLColor getColor() override {
        return {hue, cast(int, saturation), cast(int, lightness)};
    }

    void experienceEssentia() override {
        float variance = PALETTE_AXIOM_0;
        hue += variance * randomizer->generate(2);

        saturation = LIGHTNESS_AXIOM - 0.5;
        saturation = Tidbit::bind(cast(float, saturation + saturation * randomizer->generate(2)), 80.0f, 100.0f);

        lightness = LIGHTNESS_AXIOM - 0.5;
        lightness = Tidbit::bind(cast(float, lightness + lightness * randomizer->generate(3)), 70.0f, 100.0f);
    }

};

}

#endif //COSMOGRAPHER_PALETTE_H
