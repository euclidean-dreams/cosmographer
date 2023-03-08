#ifndef COSMOGRAPHER_LIFESPAN_H
#define COSMOGRAPHER_LIFESPAN_H

#include "Lively.h"
#include "cosmology/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Lifespan : public Lively {
private:
    float calculateLifespan() {
        value = constants->maxLifespan;
        if (value < 5) {
            value = 5;
        }
        return value;
    }

public:
    GlimmerSoul *glimmerSoul;
    float value;

    Lifespan(
            GlimmerSoul *glimmerSoul
    ) :
            glimmerSoul{glimmerSoul},
            value{calculateLifespan()} {}

    void live() override {
        value = calculateLifespan();
        if (glimmerSoul->age > value) {
            glimmerSoul->alive = false;
        }
    }
};

}

#endif //COSMOGRAPHER_LIFESPAN_H
