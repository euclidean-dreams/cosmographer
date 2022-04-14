#ifndef COSMOGRAPHER_AGE_H
#define COSMOGRAPHER_AGE_H

#include "Terminable.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Age : public Terminable {
public:
    GlimmerCommunity *glimmerCommunity;
    int lifespan;

    Age(
            GlimmerCommunity *glimmerCommunity,
            int lifespan
    ) :
            glimmerCommunity{glimmerCommunity},
            lifespan{lifespan} {}

    bool shouldTerminate() override {
        return glimmerCommunity->age >= lifespan;
    }
};

}

#endif //COSMOGRAPHER_AGE_H
