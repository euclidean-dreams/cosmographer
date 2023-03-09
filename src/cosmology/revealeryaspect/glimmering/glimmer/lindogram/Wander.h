#ifndef COSMOGRAPHER_WANDER_H
#define COSMOGRAPHER_WANDER_H

#include "Default.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Wander : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;

    Wander(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity
    );

    void live() override;
};

}

#endif //COSMOGRAPHER_WANDER_H
