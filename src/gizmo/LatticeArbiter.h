#ifndef COSMOGRAPHER_LATTICEARBITER_H
#define COSMOGRAPHER_LATTICEARBITER_H

#include <mutex>
#include <cosmology/Lattice.h>

namespace cosmographer {

class LatticeArbiter {
private:
    std::mutex mutex;
    std::shared_ptr<const Lattice> lattice;

public:
    LatticeArbiter();

    void updateLattice(std::unique_ptr<Lattice> newLattice);

    std::shared_ptr<const Lattice> getLattice();
};

}

#endif //COSMOGRAPHER_LATTICEARBITER_H
