#ifndef COSMOGRAPHER_PASSTHROUGHAFFINITY_H
#define COSMOGRAPHER_PASSTHROUGHAFFINITY_H

#include "Affinity.h"
#include "cosmology/aspect/Aspect.h"

namespace cosmographer {

class PassthroughAffinity : public Affinity {
private:
    std::unique_ptr<Aspect> aspect;

public:
    explicit PassthroughAffinity(std::unique_ptr<Aspect> aspect);

    std::unique_ptr<Lattice> manifest(int tick) override;

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_PASSTHROUGHAFFINITY_H
