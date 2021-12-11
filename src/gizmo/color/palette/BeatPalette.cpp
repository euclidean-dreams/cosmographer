#include "BeatPalette.h"

namespace cosmographer {

BeatPalette::BeatPalette()
        : hue{0},
          previousEnergy{0},
          lastBeat{0} {

}

HSLColor BeatPalette::getColor(int index) {
    return {Colorology::hueJitter(hue), 100, 50};
}

void BeatPalette::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    auto samples = essentia->stft();
    float energy = 0;
    for (int index = 0; index < samples->size(); index++) {
        energy += samples->Get(index);
    }
    auto flux = energy - previousEnergy;
    auto fluxRequirement = MAX_FLUX_REQUIREMENT - MAX_FLUX_REQUIREMENT * AXIOMOLOGY->getHue();
    if (flux > fluxRequirement && impresarioUtils::getElapsedTime(lastBeat) > MINIMUM_BEAT_INTERVAL) {
        hue += RANDOM.generate(HSL_HUE_MAX * AXIOMOLOGY->getWildcard(6));
    }
    previousEnergy = energy;
}

}
