#ifndef COSMOGRAPHER_JOURNEYCOLORIUM_H
#define COSMOGRAPHER_JOURNEYCOLORIUM_H

#include "gizmo/color/colorium/Colorium.h"
#include "gizmo/color/palette/FrequencyPalette.h"
#include "gizmo/color/palette/FrequencyOscillationPalette.h"
#include "gizmo/color/palette/SingleColorPalette.h"
#include "gizmo/color/palette/RandomPalette.h"
#include "gizmo/color/palette/BeatPalette.h"

namespace cosmographer {

class JourneyColorium : public Colorium {
private:
    int signalSize;

public:
    explicit JourneyColorium(int signalSize);

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_JOURNEYCOLORIUM_H
