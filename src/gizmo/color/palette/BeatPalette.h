#ifndef COSMOGRAPHER_BEATPALETTE_H
#define COSMOGRAPHER_BEATPALETTE_H

#include "gizmo/color/palette/Palette.h"

#define MAX_FLUX_REQUIREMENT (50 * 1000)
#define MINIMUM_BEAT_INTERVAL (100 * 1000)

namespace cosmographer {

class BeatPalette : public Palette {
private:
    int hue;
    float previousEnergy;
    uint64_t lastBeat;

public:
    BeatPalette();

    HSLColor getColor(int index) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_BEATPALETTE_H
