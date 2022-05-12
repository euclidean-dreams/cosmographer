#ifndef COSMOGRAPHER_CENTRIFUGALPALETTE_H
#define COSMOGRAPHER_CENTRIFUGALPALETTE_H

#include "Palette.h"
#include "oddments/SignalAverage.h"

namespace cosmographer {

class CentrifugalPalette : public Palette {
private:
    float hue;
    SignalAverage simpleMovingAverage;

public:
    CentrifugalPalette(
            uint movingAverageSize
    );

    HSLColor getColor() override;

    void experienceEssentia() override;
};

}

#endif //COSMOGRAPHER_CENTRIFUGALPALETTE_H
