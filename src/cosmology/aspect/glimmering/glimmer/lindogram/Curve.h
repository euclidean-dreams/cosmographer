#ifndef COSMOGRAPHER_CURVE_H
#define COSMOGRAPHER_CURVE_H

#include "Default.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Curve : public Lively {
public:
    GlimmerCommunity *glimmerCommunity;
    PainterCommunity *painterCommunity;
    float initialOrientation;
    float spin;

    Curve(
            GlimmerCommunity *glimmerCommunity,
            PainterCommunity *painterCommunity,
            float initialOrientation,
            float spin
    );

    void live() override;
};

}

#endif //COSMOGRAPHER_CURVE_H
