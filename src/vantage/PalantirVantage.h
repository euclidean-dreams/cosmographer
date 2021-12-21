#ifndef COSMOGRAPHER_PALANTIRVANTAGE_H
#define COSMOGRAPHER_PALANTIRVANTAGE_H

#include "vantage/Vantage.h"

namespace cosmographer {

class PalantirVantage : public Vantage {
private:
    std::unique_ptr<impresarioUtils::NetworkSocket> socket;
    std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter;
    int tickInterval;

public:
    explicit PalantirVantage(std::unique_ptr<impresarioUtils::NetworkSocket> socket,
                             std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter);

    void send(const Lattice &lattice) override;

    int getRefreshRate() override;
};

}

#endif //COSMOGRAPHER_PALANTIRVANTAGE_H
