#ifndef COSMOGRAPHER_COSMOLOGY_H
#define COSMOGRAPHER_COSMOLOGY_H

#include "CosmographerCommunity.h"
#include "CosmologyCommunity.h"
#include "vantage/Vantage.h"
#include "aspect/Aspect.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Cosmology : public Fellow<CosmographerCommunity>, public Liaison<CosmologyCommunity> {
public:
    Cosmology(
            CosmographerCommunity *community
    );

    void observe();

    void experienceEssentia();
};

}

#endif //COSMOGRAPHER_COSMOLOGY_H
