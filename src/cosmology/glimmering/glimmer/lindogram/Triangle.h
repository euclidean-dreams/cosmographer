#ifndef COSMOGRAPHER_TRIANGLE_H
#define COSMOGRAPHER_TRIANGLE_H

#include "Default.h"
#include "cosmology/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/glimmering/glimmer/lively/Lively.h"
#include "cosmology/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Triangle : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;
    float initialOrientation;

    Triangle(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity,
            float initialOrientation
    );

    void live() override;
};

}
#endif //COSMOGRAPHER_TRIANGLE_H
