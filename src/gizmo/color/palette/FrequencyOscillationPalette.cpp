#include "FrequencyOscillationPalette.h"

namespace cosmographer {

FrequencyOscillationPalette::FrequencyOscillationPalette()
        : lastOscillation{0},
          hueShift{0} {

}

HSLColor FrequencyOscillationPalette::getColor(int index) {
    if (impresarioUtils::getElapsedTime(lastOscillation) >
        MAX_OSCILLATION_RATE - MAX_OSCILLATION_RATE * AXIOMOLOGY->getHue()) {
        lastOscillation = impresarioUtils::getCurrentTime();
        hueShift++;
    }
    auto signalSize = static_cast<float>(PARADIGM.getLatticeWidth() * PARADIGM.getLatticeHeight());
    auto hue = static_cast<float>(index) / signalSize * HSL_HUE_MAX + hueShift;
    return {Colorology::hueJitter(hue), 100, 50};
}

}
