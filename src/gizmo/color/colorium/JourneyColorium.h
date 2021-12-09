#ifndef COSMOGRAPHER_JOURNEYCOLORIUM_H
#define COSMOGRAPHER_JOURNEYCOLORIUM_H

#include "gizmo/color/colorium/Colorium.h"
#include "gizmo/color/palette/FrequencyPalette.h"
#include "gizmo/color/palette/SingleColorPalette.h"
#include "gizmo/color/palette/RandomPalette.h"

namespace cosmographer {

class JourneyColorium : public Colorium {
private:
    int signalSize;

public:
    explicit JourneyColorium(int signalSize);

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;
};

}

#endif //COSMOGRAPHER_JOURNEYCOLORIUM_H
