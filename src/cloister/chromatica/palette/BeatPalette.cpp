#include "BeatPalette.h"

namespace cosmographer {

BeatPalette::BeatPalette() :
        hue{0},
        previousEnergy{0},
        lastBeat{0} {

}

HSLColor BeatPalette::getColor() {
    return CLOISTER->colorPixie->hueJitter({hue, 100, 50});
}

void BeatPalette::experienceEssentia(const Essentia *essentia) {
    auto samples = essentia->stft();
    float energy = 0;
    for (int index = 0; index < samples->size(); index++) {
        energy += samples->Get(index);
    }
    auto flux = energy - previousEnergy;
    auto fluxRequirement = CONSTANTS->maxFluxRequirement - CONSTANTS->maxFluxRequirement * PALETTE_AXIOM_0;
    if (flux > fluxRequirement && getElapsedTime(lastBeat) > CONSTANTS->minimumBeatInterval) {
        hue += CLOISTER->randomizer->generate(HSL_HUE_MAX * PALETTE_AXIOM_0);
    }
    previousEnergy = energy;
}

}
