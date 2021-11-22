#include "LatticeArbiter.h"

namespace cosmographer {

LatticeArbiter::LatticeArbiter()
        : mutex{},
          lattice{} {

}

void LatticeArbiter::updateLattice(std::unique_ptr<Lattice> newLattice) {
    std::lock_guard<std::mutex> lock{mutex};
    lattice = move(newLattice);
}

std::shared_ptr<const Lattice> LatticeArbiter::getLattice() {
    std::lock_guard<std::mutex> lock{mutex};
    return lattice;
}

}
