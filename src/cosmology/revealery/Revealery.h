#ifndef COSMOGRAPHER_REVEALERY_H
#define COSMOGRAPHER_REVEALERY_H

#include "cosmology/RevealeryAspectCommunity.h"
#include "cosmology/glimmering/Glimmering.h"
#include "cosmology/mesh/lumion/Lumion.h"

namespace cosmographer {

class Revealery : public Fellow<RevealeryAspectCommunity> {
public:
    virtual void reveal(
            Lumion *lumion
    ) = 0;

    virtual void experienceSignal() {};
};

}

#endif //COSMOGRAPHER_REVEALERY_H
