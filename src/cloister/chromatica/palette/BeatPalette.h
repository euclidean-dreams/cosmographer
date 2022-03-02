#ifndef COSMOGRAPHER_BEATPALETTE_H
#define COSMOGRAPHER_BEATPALETTE_H

#include "Palette.h"

namespace cosmographer {

class BeatPalette : public Palette {
private:
    int hue;
    float previousEnergy;
    uint64_t lastBeat;

public:
    BeatPalette();

    HSLColor getColor() override;

    void experienceEssentia(const Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_BEATPALETTE_H
