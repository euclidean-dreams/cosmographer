#ifndef COSMOGRAPHER_REVEALERY_H
#define COSMOGRAPHER_REVEALERY_H

#include "cosmology/aspect/glimmering/GlimmeringCommunity.h"
#include "cosmology/aspect/mesh/lumion/Lumion.h"

namespace cosmographer {

class Revealery : public Fellow<GlimmeringCommunity> {
public:
    virtual void reveal(
            LumionExcitation excitation
    ) = 0;
};

}

#endif //COSMOGRAPHER_REVEALERY_H
