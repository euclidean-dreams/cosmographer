#include "Cosmographer.h"

namespace cosmographer {

Cosmographer::Cosmographer(
        std::unique_ptr<std::vector<std::unique_ptr<impresarioUtils::PacketReceiver>>> packetReceivers,
        std::shared_ptr<LatticeArbiter> latticeArbiter)
        : packetReceivers{move(packetReceivers)},
          latticeArbiter{move(latticeArbiter)},
          cosmology{} {

}

void Cosmographer::activate() {
    handleIncomingPackets();
    auto lattice = cosmology.observe();
    latticeArbiter->updateLattice(move(lattice));
}

void Cosmographer::handleIncomingPackets() {
    for (auto &packetReceiver: *packetReceivers) {
        auto packets = packetReceiver->receive();
        while (packets->morePacketsLeft()) {
            auto packet = packets->popPacket();
            cosmology.alter(*packet);
        }
    }
}

uint64_t Cosmographer::getTickInterval() {
    return 3 * 1000;
}

bool Cosmographer::finished() {
    return false;
}

}
