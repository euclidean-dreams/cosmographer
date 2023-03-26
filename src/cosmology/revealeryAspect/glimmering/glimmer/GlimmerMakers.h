#ifndef COSMOGRAPHER_GLIMMERMAKERS_H
#define COSMOGRAPHER_GLIMMERMAKERS_H

#include "Glimmer.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"

namespace cosmographer {

class GlimmerMakers {
public:
    static PainterCommunity *createPainterCommunity(
            Glimmer *glimmer,
            bool singleColorCanvas = true
    );
};

}

#endif //COSMOGRAPHER_GLIMMERMAKERS_H
