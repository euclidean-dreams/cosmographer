#ifndef COSMOGRAPHER_WORKSHOPCURVE_H
#define COSMOGRAPHER_WORKSHOPCURVE_H

#include "Default.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class WorkshopCurve : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;
    float initialOrientation;

    WorkshopCurve(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity,
            float initialOrientation
    );

    void live() override;
};

}

#endif //COSMOGRAPHER_WORKSHOPCURVE_H
