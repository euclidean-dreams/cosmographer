#ifndef COSMOGRAPHER_PALANTIRVANTAGE_H
#define COSMOGRAPHER_PALANTIRVANTAGE_H

#include "vantage/Vantage.h"

namespace cosmographer {

class PalantirVantage : public Vantage {
public:
    up<NetworkSocket> socket;

    PalantirVantage(
            up<NetworkSocket> socket
    );

    void send(const Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_PALANTIRVANTAGE_H
