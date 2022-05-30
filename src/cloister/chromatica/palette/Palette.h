#ifndef COSMOGRAPHER_PALETTE_H
#define COSMOGRAPHER_PALETTE_H

#include "Default.h"
#include "cloister/chromatica/ChromaticaCommunity.h"
#include "cloister/ColorPixie.h"
#include "primitive/color/HSLColor.h"

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

}

#endif //COSMOGRAPHER_PALETTE_H
