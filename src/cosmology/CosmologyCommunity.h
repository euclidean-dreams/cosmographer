#ifndef COSMOGRAPHER_COSMOLOGYCOMMUNITY_H
#define COSMOGRAPHER_COSMOLOGYCOMMUNITY_H

#include "Default.h"

namespace cosmographer {

class CosmologyCommunity : public Community {
public:
    up<class Aspect> aspect;
};

}

#endif //COSMOGRAPHER_COSMOLOGYCOMMUNITY_H
