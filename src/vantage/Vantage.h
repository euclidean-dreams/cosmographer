#ifndef COSMOGRAPHER_VANTAGE_H
#define COSMOGRAPHER_VANTAGE_H

#include "CosmographerCommunity.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Vantage : public Fellow<CosmographerCommunity> {
public:
    virtual void send(const Lattice &lattice) = 0;
};

}

#endif //COSMOGRAPHER_VANTAGE_H
