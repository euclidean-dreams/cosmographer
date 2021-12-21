#include "FrequencyPalette.h"

namespace cosmographer {

HSLColor FrequencyPalette::getColor(int index) {
    auto signalSize = static_cast<float>(PARADIGM.getLatticeWidth() * PARADIGM.getLatticeHeight());
    auto hue = static_cast<float>(index) / signalSize * HSL_HUE_MAX - AXIOMOLOGY.getScaledHue();
    return {Colorology::hueJitter(hue), 100, 50};
}

}
