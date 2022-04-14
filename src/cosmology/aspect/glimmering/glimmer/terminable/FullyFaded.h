#ifndef COSMOGRAPHER_FULLYFADED_H
#define COSMOGRAPHER_FULLYFADED_H

#include "Terminable.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class FullyFaded : public Terminable {
public:
    GlimmerCommunity *glimmerCommunity;

    FullyFaded(
            GlimmerCommunity *glimmerCommunity
    ) :
            glimmerCommunity{glimmerCommunity} {}

    bool shouldTerminate() override {
        return glimmerCommunity->color == glimmerCommunity->paradigm->cloister->constants->latticeInitialColor;
    }
};

}

#endif //COSMOGRAPHER_FULLYFADED_H
