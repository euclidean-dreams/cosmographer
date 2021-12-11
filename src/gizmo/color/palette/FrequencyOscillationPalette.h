#ifndef COSMOGRAPHER_FREQUENCYOSCILLATIONPALETTE_H
#define COSMOGRAPHER_FREQUENCYOSCILLATIONPALETTE_H

#include "gizmo/color/palette/Palette.h"

#define MAX_OSCILLATION_RATE (15 * 1000)

namespace cosmographer {

class FrequencyOscillationPalette : public Palette {
private:
    uint64_t lastOscillation;
    int hueShift;

public:
    FrequencyOscillationPalette();

    HSLColor getColor(int index) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override {};
};

}

#endif //COSMOGRAPHER_FREQUENCYOSCILLATIONPALETTE_H
