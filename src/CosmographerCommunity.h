#ifndef COSMOGRAPHER_COSMOGRAPHERCOMMUNITY_H
#define COSMOGRAPHER_COSMOGRAPHERCOMMUNITY_H

#include "Default.h"

namespace cosmographer {

class CosmographerCommunity : public Community {
public:
    up<class Vantage> vantage;
    up<class Cosmology> cosmology;
    up<NetworkSocket> essentiaSocket;
    sp<BufferArbiter<const Parcel>> phenomenology;
};

}

#endif //COSMOGRAPHER_COSMOGRAPHERCOMMUNITY_H
