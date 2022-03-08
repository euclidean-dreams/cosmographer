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
    auto fluxRequirement = MAX_FLUX_REQUIREMENT - MAX_FLUX_REQUIREMENT * PALETTE_AXIOM_0;
    if (flux > fluxRequirement && getElapsedTime(lastBeat) > MINIMUM_BEAT_INTERVAL) {
        hue += RANDOM.generate(HSL_HUE_MAX * PALETTE_AXIOM_1);
    }
    previousEnergy = energy;
}

}
