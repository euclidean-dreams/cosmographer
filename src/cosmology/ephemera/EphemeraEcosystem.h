#ifndef COSMOGRAPHER_EPHEMERAECOSYSTEM_H
#define COSMOGRAPHER_EPHEMERAECOSYSTEM_H

#include "cosmology/ephemera/Ephemera.h"

namespace cosmographer {

class EphemeraEcosystem {
private:
    std::list<std::unique_ptr<Ephemera>> ecosystem;

public:
    void add(std::unique_ptr<Ephemera> ephemera);

    void observe(Lattice &lattice);
};

}

#endif //COSMOGRAPHER_EPHEMERAECOSYSTEM_H
