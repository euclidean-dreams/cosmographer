#ifndef COSMOGRAPHER_LIFESPAN_H
#define COSMOGRAPHER_LIFESPAN_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Lifespan : public Lively {
public:
    GlimmerCommunity *glimmerCommunity;

    Lifespan(
            GlimmerCommunity *glimmerCommunity
    ) :
            glimmerCommunity{glimmerCommunity} {}

    void live() override {
        auto lifespan = glimmerCommunity->paradigm->cloister->constants->maxLifespan
                        * glimmerCommunity->paradigm->axioms[7];
        if (lifespan < 5) {
            lifespan = 5;
        }
        if (glimmerCommunity->age > lifespan) {
            glimmerCommunity->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_LIFESPAN_H
