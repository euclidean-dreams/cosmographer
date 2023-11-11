#ifndef COSMOGRAPHER_FUZZ_H
#define COSMOGRAPHER_FUZZ_H

#include "Default.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Fuzz : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;

    Fuzz(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity
    );

    void live() override;
};

}
#endif //COSMOGRAPHER_FUZZ_H
