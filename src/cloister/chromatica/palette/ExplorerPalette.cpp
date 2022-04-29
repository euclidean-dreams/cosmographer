#include "ExplorerPalette.h"

namespace cosmographer {

ExplorerPalette::ExplorerPalette(

) :
        hue{cast(float, CONSTANTS->latticeInitialColor.hue)},
        saturation{50},
        lightness{50} {

}

HSLColor ExplorerPalette::getColor() {
    return {hue, cast(int, saturation), cast(int, lightness)};
}

void ExplorerPalette::experienceEssentia() {
    float variance = PALETTE_AXIOM_0;
    hue += variance * RANDOM.generate(2);
}

}
