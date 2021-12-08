#ifndef COSMOGRAPHER_LUCIFERONVANTAGE_H
#define COSMOGRAPHER_LUCIFERONVANTAGE_H

#include "vantage/Vantage.h"

namespace cosmographer {

class LuciferonVantage : public Vantage {
private:
    std::unique_ptr<impresarioUtils::NetworkSocket> socket;
    int tickInterval;

public:
    explicit LuciferonVantage(std::unique_ptr<impresarioUtils::NetworkSocket> socket);

    void send(const Lattice &lattice) override;

    int getRefreshRate() override;
};

}

#endif //COSMOGRAPHER_LUCIFERONVANTAGE_H
