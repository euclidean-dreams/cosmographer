#ifndef COSMOGRAPHER_ASPECTCOMMUNITY_H
#define COSMOGRAPHER_ASPECTCOMMUNITY_H

#include "default.h"

namespace cosmographer {

class AspectCommunity : public Community {
public:
    up<class Glimmering> glimmering;
    up<class Mesh> mesh;
};

}

#endif //COSMOGRAPHER_ASPECTCOMMUNITY_H
