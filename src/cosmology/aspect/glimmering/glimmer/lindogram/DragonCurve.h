#ifndef COSMOGRAPHER_DRAGONCURVE_H
#define COSMOGRAPHER_DRAGONCURVE_H

#include "Default.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class DragonCurve : public Lively {
public:
    GlimmerCommunity *glimmerCommunity;
    PainterCommunity *painterCommunity;
    float initialOrientation;
    int lastRuneIndex;

    DragonCurve(
            GlimmerCommunity *glimmerCommunity,
            PainterCommunity *painterCommunity,
            float initialOrientation
    );

    void live() override;
};

}

#endif //COSMOGRAPHER_DRAGONCURVE_H
