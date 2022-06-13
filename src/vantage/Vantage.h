#ifndef COSMOGRAPHER_VANTAGE_H
#define COSMOGRAPHER_VANTAGE_H

#include "Default.h"
#include "primitive/Lattice.h"
#include "CosmographerCommunity.h"

namespace cosmographer {

class Vantage : public Fellow<CosmographerCommunity> {
public:
    up<NetworkSocket> socket;

    Vantage(
            up<NetworkSocket> socket
    );

    void send(const Lattice &lattice);
};

}

#endif //COSMOGRAPHER_VANTAGE_H
