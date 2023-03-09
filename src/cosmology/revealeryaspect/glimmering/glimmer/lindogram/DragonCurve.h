#ifndef COSMOGRAPHER_DRAGONCURVE_H
#define COSMOGRAPHER_DRAGONCURVE_H

#include "Default.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class DragonCurve : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;
    float initialOrientation;
    int lastRuneIndex;

    DragonCurve(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity,
            float initialOrientation
    );

    void live() override;
};

}

#endif //COSMOGRAPHER_DRAGONCURVE_H
