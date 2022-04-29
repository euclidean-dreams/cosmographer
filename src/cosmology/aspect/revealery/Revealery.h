#ifndef COSMOGRAPHER_REVEALERY_H
#define COSMOGRAPHER_REVEALERY_H

#include "cosmology/aspect/AspectCommunity.h"
#include "cosmology/aspect/glimmering/Glimmering.h"
#include "cosmology/aspect/mesh/lumion/Lumion.h"

namespace cosmographer {

class Revealery : public Fellow<AspectCommunity> {
public:
    virtual void reveal(
            Lumion *lumion
    ) = 0;

    virtual void experienceSignal() {};
};

}

#endif //COSMOGRAPHER_REVEALERY_H
