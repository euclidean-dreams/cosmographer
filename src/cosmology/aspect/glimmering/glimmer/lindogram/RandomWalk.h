#ifndef COSMOGRAPHER_RANDOMWALK_H
#define COSMOGRAPHER_RANDOMWALK_H

#include "Default.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class RandomWalk : public Lively {
public:
    GlimmerCommunity *glimmerCommunity;
    PainterCommunity *painterCommunity;
    float initialOrientation;
    float spin;
    bool initialized;

    RandomWalk(
            GlimmerCommunity *glimmerCommunity,
            PainterCommunity *painterCommunity,
            float initialOrientation,
            float spin
    );

    void live() override;
};

}

#endif //COSMOGRAPHER_RANDOMWALK_H
