#ifndef COSMOGRAPHER_PERCIPIAVANTAGE_H
#define COSMOGRAPHER_PERCIPIAVANTAGE_H

#include "vantage/Vantage.h"

namespace cosmographer {

class PercipiaVantage : public Vantage {
public:
    up<NetworkSocket> socket;

    PercipiaVantage(
            up<NetworkSocket> socket
    );

    void send(const Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_PERCIPIAVANTAGE_H
