#ifndef COSMOGRAPHER_LUCIFERONVANTAGE_H
#define COSMOGRAPHER_LUCIFERONVANTAGE_H

#include <ImpresarioUtils.h>
#include "gizmo/LatticeArbiter.h"
#include "Constants.h"

namespace cosmographer {

class LuciferonVantage : public impresarioUtils::Circulable {
private:
    std::shared_ptr<LatticeArbiter> latticeArbiter;
    std::unique_ptr<impresarioUtils::NetworkSocket> socket;

public:
    LuciferonVantage(std::shared_ptr<LatticeArbiter> latticeArbiter,
                     std::unique_ptr<impresarioUtils::NetworkSocket> socket);

    void activate() override;

    uint64_t getTickInterval() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_LUCIFERONVANTAGE_H
