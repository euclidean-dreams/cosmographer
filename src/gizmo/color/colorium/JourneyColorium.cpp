#include "JourneyColorium.h"

namespace cosmographer {

JourneyColorium::JourneyColorium(int signalSize)
        : Colorium(std::make_unique<FrequencyPalette>()),
          signalSize{signalSize} {

}

void JourneyColorium::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    if (phenomenon->identity() == 0) {
        palette = std::make_unique<FrequencyPalette>();
    } else if (phenomenon->identity() == 1) {
        palette = std::make_unique<SingleColorPalette>();
    } else if (phenomenon->identity() == 2) {
        palette = std::make_unique<RandomPalette>();
    }
}

}
