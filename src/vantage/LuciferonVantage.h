#ifndef COSMOGRAPHER_LUCIFERONVANTAGE_H
#define COSMOGRAPHER_LUCIFERONVANTAGE_H

#include "vantage/Vantage.h"

namespace cosmographer {

class LuciferonVantage : public Vantage {
private:
    std::unique_ptr<impresarioUtils::NetworkSocket> socket0;
    std::unique_ptr<impresarioUtils::NetworkSocket> socket1;
    std::unique_ptr<impresarioUtils::NetworkSocket> socket2;
    std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter;
    int tickInterval;

public:
    explicit LuciferonVantage(std::unique_ptr<impresarioUtils::NetworkSocket> socket0,
                              std::unique_ptr<impresarioUtils::NetworkSocket> socket1,
                              std::unique_ptr<impresarioUtils::NetworkSocket> socket2,
                              std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter);

    void send(const Lattice &lattice) override;

    int getRefreshRate() override;
};

}

#endif //COSMOGRAPHER_LUCIFERONVANTAGE_H
