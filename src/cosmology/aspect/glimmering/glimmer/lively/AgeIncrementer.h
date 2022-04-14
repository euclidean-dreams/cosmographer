#ifndef COSMOGRAPHER_AGEINCREMENTER_H
#define COSMOGRAPHER_AGEINCREMENTER_H

#include "Lively.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class AgeIncrementer : public Lively {
public:
    GlimmerCommunity *glimmerCommunity;

    AgeIncrementer(
            GlimmerCommunity *glimmerCommunity
    ) :
            glimmerCommunity{glimmerCommunity} {

    }

    void live() override {
        glimmerCommunity->age++;
    }
};

}

#endif //COSMOGRAPHER_AGEINCREMENTER_H
