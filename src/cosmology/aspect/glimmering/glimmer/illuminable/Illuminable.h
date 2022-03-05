#ifndef COSMOGRAPHER_ILLUMINABLE_H
#define COSMOGRAPHER_ILLUMINABLE_H

#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Illuminable : public Fellow<GlimmerCommunity> {
public:
    virtual void illuminate(
            Lattice &lattice
    ) = 0;
};

}

#endif //COSMOGRAPHER_ILLUMINABLE_H