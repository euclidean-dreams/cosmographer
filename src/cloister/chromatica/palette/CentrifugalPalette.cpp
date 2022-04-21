#include "CentrifugalPalette.h"

namespace cosmographer {

CentrifugalPalette::CentrifugalPalette(
        uint movingAverageSize
) :
        hue{0},
        simpleMovingAverage{movingAverageSize} {

}

HSLColor CentrifugalPalette::getColor() {
    return {hue, 100, 50};
}

void CentrifugalPalette::experienceEssentia(const Essentia *essentia) {
    auto samples = essentia->stft();
    float energy = 0;
    for (int index = 0; index < samples->size(); index++) {
        auto sample = samples->Get(index);
        energy += sample;
    }
    auto flux = energy - simpleMovingAverage.calculate();
    simpleMovingAverage.addSample(energy);
    auto fluxModifier = PALETTE_AXIOM_0;
    if (fluxModifier < 0.01) {
        fluxModifier = 0.01;
    }
    auto hueAddendum = (flux / CONSTANTS->centrifugalPaletteFlux) * fluxModifier;
    hue += hueAddendum;
}

}
