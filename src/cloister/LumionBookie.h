#ifndef COSMOGRAPHER_LUMIONBOOKIE_H
#define COSMOGRAPHER_LUMIONBOOKIE_H

#include "CloisterCommunity.h"

namespace cosmographer {

class LumionBookie : public Fellow<CloisterCommunity> {
public:
    int activationCount;
    float maxActivation;

    LumionBookie();

    void recordActivation(float activation);

    void clear();
};

}

#endif //COSMOGRAPHER_LUMIONBOOKIE_H
