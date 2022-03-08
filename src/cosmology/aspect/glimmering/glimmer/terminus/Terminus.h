#ifndef COSMOGRAPHER_TERMINUS_H
#define COSMOGRAPHER_TERMINUS_H

#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Terminus : public Fellow<GlimmerCommunity> {
public:
    virtual bool shouldTerminate() = 0;
};

}

#endif //COSMOGRAPHER_TERMINUS_H
