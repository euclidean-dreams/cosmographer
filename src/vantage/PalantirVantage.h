#ifndef COSMOGRAPHER_PALANTIRVANTAGE_H
#define COSMOGRAPHER_PALANTIRVANTAGE_H

#include <ImpresarioUtils.h>
#include "gizmo/LatticeArbiter.h"
#include "Constants.h"

namespace cosmographer {

class PalantirVantage : public impresarioUtils::Circulable {
private:
    std::shared_ptr<LatticeArbiter> latticeArbiter;
    std::unique_ptr<impresarioUtils::NetworkSocket> socket;

public:
    PalantirVantage(std::shared_ptr<LatticeArbiter> latticeArbiter,
                    std::unique_ptr<impresarioUtils::NetworkSocket> socket);

    void activate() override;

    uint64_t getTickInterval() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_PALANTIRVANTAGE_H
