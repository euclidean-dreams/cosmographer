#ifndef COSMOGRAPHER_REVEALERYASPECTCOMMUNITY_H
#define COSMOGRAPHER_REVEALERYASPECTCOMMUNITY_H

#include "Default.h"

namespace cosmographer {

class RevealeryAspectCommunity : public Community {
public:
    up<class Glimmering> glimmering;
    up<class Mesh> mesh;
    vec<up<class Revealery>> revealeries;
};

}

#endif //COSMOGRAPHER_REVEALERYASPECTCOMMUNITY_H
