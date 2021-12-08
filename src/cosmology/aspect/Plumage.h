#ifndef COSMOGRAPHER_PLUMAGE_H
#define COSMOGRAPHER_PLUMAGE_H

#include "Aspect.h"
#include "cosmology/ephemera/Bloom.h"

namespace cosmographer {

class Plumage : public Aspect {
private:
    EphemeraEcosystem ecosystem;

public:
    Plumage(uint latticeWidth, uint latticeHeight);

    std::unique_ptr<Lattice> manifest(int tick) override;

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_PLUMAGE_H
