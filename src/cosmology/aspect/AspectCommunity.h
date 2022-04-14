#ifndef COSMOGRAPHER_ASPECTCOMMUNITY_H
#define COSMOGRAPHER_ASPECTCOMMUNITY_H

#include "Default.h"

namespace cosmographer {

class AspectCommunity : public Community {
public:
    up<class Glimmering> glimmering;
    up<class Mesh> mesh;
    vec<up<class Revealery>> revealeries;
};

}

#endif //COSMOGRAPHER_ASPECTCOMMUNITY_H
