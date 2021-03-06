#include "ExplorerPalette.h"
#include "oddments/Tidbit.h"

namespace cosmographer {

ExplorerPalette::ExplorerPalette(

) :
        hue{cast(float, constants->latticeInitialColor.hue)},
        saturation{100},
        lightness{80} {

}

HSLColor ExplorerPalette::getColor() {
    return {hue, cast(int, saturation), cast(int, lightness)};
}

void ExplorerPalette::experienceEssentia() {
    float variance = PALETTE_AXIOM_0;
    hue += variance * randomizer->generate(2);

    saturation = LIGHTNESS_AXIOM - 0.5;
    saturation = Tidbit::bind(cast(float, saturation + saturation * randomizer->generate(2)), 80.0f, 100.0f);

    lightness = LIGHTNESS_AXIOM - 0.5;
    lightness = Tidbit::bind(cast(float, lightness + lightness * randomizer->generate(3)), 70.0f, 100.0f);
}

}
