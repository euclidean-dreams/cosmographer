#ifndef COSMOGRAPHER_RING_H
#define COSMOGRAPHER_RING_H

#include "Default.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Ring : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;

    Ring(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity
    );

    void live() override;
};

}
#endif //COSMOGRAPHER_RING_H
