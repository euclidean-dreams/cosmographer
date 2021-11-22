#ifndef COSMOGRAPHER_COSMOGRAPHER_H
#define COSMOGRAPHER_COSMOGRAPHER_H

#include <ImpresarioUtils.h>
#include "gizmo/LatticeArbiter.h"
#include "cosmology/Cosmology.h"

namespace cosmographer {

class Cosmographer : public impresarioUtils::Circulable {
private:
    std::shared_ptr<LatticeArbiter> latticeArbiter;
    std::unique_ptr<std::vector<std::unique_ptr<impresarioUtils::PacketReceiver>>> packetReceivers;
    Cosmology cosmology;

    void handleIncomingPackets();

public:
    explicit Cosmographer(
            std::unique_ptr<std::vector<std::unique_ptr<impresarioUtils::PacketReceiver>>> packetReceivers,
            std::shared_ptr<LatticeArbiter> latticeArbiter);

    void activate() override;

    uint64_t getTickInterval() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_COSMOGRAPHER_H
