#ifndef COSMOGRAPHER_CENTRIFUGALPALETTE_H
#define COSMOGRAPHER_CENTRIFUGALPALETTE_H

#include "Palette.h"
#include "oddments/SimpleMovingAverage.h"

namespace cosmographer {

class CentrifugalPalette : public Palette {
private:
    float hue;
    SimpleMovingAverage simpleMovingAverage;

public:
    CentrifugalPalette(
            uint movingAverageSize
    );

    HSLColor getColor() override;

    void experienceEssentia() override;
};

}

#endif //COSMOGRAPHER_CENTRIFUGALPALETTE_H
