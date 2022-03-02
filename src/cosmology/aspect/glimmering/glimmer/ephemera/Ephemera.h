#ifndef COSMOGRAPHER_EPHEMERA_H
#define COSMOGRAPHER_EPHEMERA_H

#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Ephemera : public Fellow<GlimmerCommunity> {
public:
    virtual void live() = 0;

    virtual bool isAlive() = 0;
};

}

#endif //COSMOGRAPHER_EPHEMERA_H
