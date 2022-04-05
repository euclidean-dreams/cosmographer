#ifndef COSMOGRAPHER_EPHEMERA_H
#define COSMOGRAPHER_EPHEMERA_H

#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Ephemera : public Fellow<GlimmerCommunity> {
public:
    virtual ~Ephemera() = default;

    virtual void live() = 0;
};

}

#endif //COSMOGRAPHER_EPHEMERA_H
