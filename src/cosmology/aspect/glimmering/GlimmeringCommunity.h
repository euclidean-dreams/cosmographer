#ifndef COSMOGRAPHER_GLIMMERINGCOMMUNITY_H
#define COSMOGRAPHER_GLIMMERINGCOMMUNITY_H

#include "default.h"

namespace cosmographer {

class GlimmeringCommunity : public Community {
public:
    lst<up<class Glimmer>> glimmers;
    up<class Revealery> revealery;
};

}

#endif //COSMOGRAPHER_GLIMMERINGCOMMUNITY_H
