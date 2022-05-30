#include "BeatPalette.h"

namespace cosmographer {

BeatPalette::BeatPalette() :
        hue{0},
        previousEnergy{0},
        lastBeat{0} {

}

HSLColor BeatPalette::getColor() {
    return jitter({hue, 100, 70});
}

void BeatPalette::experienceEssentia() {
    auto &stft = signalarium->stft;
    auto flux = stft.energy - previousEnergy;
    auto fluxRequirement = constants->maxFluxRequirement - constants->maxFluxRequirement * PALETTE_AXIOM_0;
    if (flux > fluxRequirement && getElapsedTime(lastBeat) > constants->minimumBeatInterval) {
        hue += randomizer->generate(HSL_HUE_MAX * PALETTE_AXIOM_0);
    }
    previousEnergy = stft.energy;
}

}
