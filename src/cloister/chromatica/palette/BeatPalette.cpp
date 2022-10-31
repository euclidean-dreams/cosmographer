#include "BeatPalette.h"

namespace cosmographer {

BeatPalette::BeatPalette() :
        hue{0},
        previousEnergy{0},
        lastBeat{0} {

}

HSLColor BeatPalette::get_color() {
    return jitter({hue, 100, 70});
}

void BeatPalette::experienceEssentia() {
    auto &stft = signalarium->stft;
    auto flux = stft.energy - previousEnergy;
    auto fluxRequirement = constants->maxFluxRequirement - constants->maxFluxRequirement * COLOR_BASE_AXIOM;
    if (flux > fluxRequirement && getElapsedTime(lastBeat) > constants->minimumBeatInterval) {
        hue += randomizer->generate(HSL_HUE_MAX * COLOR_BASE_AXIOM);
    }
    previousEnergy = stft.energy;
}

}
