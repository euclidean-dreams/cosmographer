#include "Signal.h"

namespace cosmographer {

Signal::Signal(HSLColor soulColor, std::vector<float> signal)
        : Illuminable{soulColor},
          signal{move(signal)} {

}

void Signal::illuminate(Lattice &lattice) {
    for (int index = 0; index < signal.size(); index++) {
        auto coordinate = CoordinateTransformer::verticalWrap(index);
        if (signal[index] > 0) {
            auto color = soulColor.lighten(signal[index] / 10);
            lattice.setColor(coordinate, color);
        }
    }
}

}
