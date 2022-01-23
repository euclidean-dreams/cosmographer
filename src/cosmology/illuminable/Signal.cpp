#include "Signal.h"

namespace cosmographer {

Signal::Signal(Coordinate origin, HSLColor soulColor, std::vector<float> samples)
        : Illuminable{soulColor},
          samples{move(samples)} {

}

void Signal::illuminate(Lattice &lattice) {
    auto normalizationScale = AXIOMOLOGY.getEphemeraNormalizationScale();
    for (int index = 0; index < samples.size(); index++) {
        auto coordinate = CoordinateTransformer::verticalWrap(index);
        if (samples[index] > 0) {
            auto maxLightness = 100;
            auto lightness = maxLightness - maxLightness /
                                            (std::pow(samples[index] / (-1 * (1000 - 1000 * normalizationScale)), 2) +
                                             1);
            auto color = soulColor.newLightness(lightness);
            lattice.setColor(coordinate, color);
        }
    }
}

}
