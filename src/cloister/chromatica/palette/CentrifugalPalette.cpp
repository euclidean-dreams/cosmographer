#include "CentrifugalPalette.h"

namespace cosmographer {

CentrifugalPalette::CentrifugalPalette(
        uint movingAverageSize
) :
        hue{0},
        simpleMovingAverage{movingAverageSize} {

}

HSLColor CentrifugalPalette::getColor() {
    return {hue, 100, 80};
}

void CentrifugalPalette::experienceEssentia() {
    auto &stft = CLOISTER->signalarium->stft;
    auto flux = stft.energy - simpleMovingAverage.calculate();
    simpleMovingAverage.addSample(stft.energy);
    auto fluxModifier = PALETTE_AXIOM_0;
    if (fluxModifier < 0.01) {
        fluxModifier = 0.01;
    }
    auto hueAddendum = (flux / CONSTANTS->centrifugalPaletteFlux) * fluxModifier;
    hue += hueAddendum;
}

}
