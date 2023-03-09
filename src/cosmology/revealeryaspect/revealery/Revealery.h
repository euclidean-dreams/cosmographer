#ifndef COSMOGRAPHER_REVEALERY_H
#define COSMOGRAPHER_REVEALERY_H

#include "cosmology/revealeryaspect/RevealeryAspectCommunity.h"
#include "cosmology/revealeryaspect/glimmering/Glimmering.h"
#include "cosmology/revealeryaspect/mesh/lumion/Lumion.h"

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
