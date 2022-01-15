#ifndef COSMOGRAPHER_PALANTIRVANTAGE_H
#define COSMOGRAPHER_PALANTIRVANTAGE_H

#include "vantage/Vantage.h"

namespace cosmographer {

class PalantirVantage : public Vantage {
private:
    std::unique_ptr<impresarioUtils::NetworkSocket> socket;

public:
    explicit PalantirVantage(std::unique_ptr<impresarioUtils::NetworkSocket> socket);

    void send(const Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_PALANTIRVANTAGE_H
