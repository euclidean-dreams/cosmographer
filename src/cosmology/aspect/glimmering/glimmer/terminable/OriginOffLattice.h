#ifndef COSMOGRAPHER_ORIGINOFFLATTICE_H
#define COSMOGRAPHER_ORIGINOFFLATTICE_H

#include "Terminable.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class OriginOffLattice : public Terminable {
public:
    GlimmerCommunity *glimmerCommunity;

    OriginOffLattice(
            GlimmerCommunity *glimmerCommunity
    ) :
            glimmerCommunity{glimmerCommunity} {}

    bool shouldTerminate() override {
        return !glimmerCommunity->paradigm->cloister->cartographer->isValid(glimmerCommunity->locus);
    }
};

}

#endif //COSMOGRAPHER_ORIGINOFFLATTICE_H
