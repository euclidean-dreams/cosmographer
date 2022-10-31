#include "CentrifugalPalette.h"

namespace cosmographer {

CentrifugalPalette::CentrifugalPalette(
        uint movingAverageSize
) :
        hue{0},
        simpleMovingAverage{movingAverageSize} {

}

HSLColor CentrifugalPalette::get_color() {
    return jitter({hue, 100, 70});
}

void CentrifugalPalette::experienceEssentia() {
    auto &stft = signalarium->stft;
    auto flux = stft.energy - simpleMovingAverage.value;
    simpleMovingAverage.addSample(stft.energy);
    auto fluxModifier = COLOR_BASE_AXIOM;
    if (fluxModifier < 0.01) {
        fluxModifier = 0.01;
    }
    auto hueAddendum = (flux / constants->centrifugalPaletteFlux) * fluxModifier;
    hue += hueAddendum;
}

}
