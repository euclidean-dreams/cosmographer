#ifndef COSMOGRAPHER_LIFESPAN_H
#define COSMOGRAPHER_LIFESPAN_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Lifespan : public Lively {
public:
    GlimmerSoul *glimmerSoul;

    Lifespan(
            GlimmerSoul *glimmerSoul
    ) :
            glimmerSoul{glimmerSoul} {}

    void live() override {
        auto lifespan = paradigm->cloister->constants->maxLifespan
                        * paradigm->axioms[7];
        if (lifespan < 5) {
            lifespan = 5;
        }
        if (glimmerSoul->age > lifespan) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_LIFESPAN_H
