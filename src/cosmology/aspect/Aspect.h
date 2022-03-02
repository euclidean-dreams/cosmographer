#ifndef COSMOGRAPHER_ASPECT_H
#define COSMOGRAPHER_ASPECT_H

#include "cosmology/CosmologyCommunity.h"
#include "AspectCommunity.h"
#include "primitive/Lattice.h"
#include "glimmering/Glimmering.h"
#include "mesh/Mesh.h"
#include "cosmology/aspect/glimmering/revealery/CircleRevealery.h"

namespace cosmographer {

class Aspect : public Fellow<CosmologyCommunity>, public Liaison<AspectCommunity> {
public:
    Aspect(
            CosmologyCommunity *community
    );

    up<Lattice> manifest();

    void experienceEssentia(const Essentia *essentia);
};

}

#endif //COSMOGRAPHER_ASPECT_H
