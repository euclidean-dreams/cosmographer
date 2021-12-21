#ifndef COSMOGRAPHER_OVERLAPAFFINITY_H
#define COSMOGRAPHER_OVERLAPAFFINITY_H

#include "Affinity.h"
#include "cosmology/aspect/Aspect.h"

namespace cosmographer {

class OverlapAffinity : public Affinity {
private:
    std::unique_ptr<std::vector<std::unique_ptr<Aspect>>> aspects;

public:
    explicit OverlapAffinity(std::unique_ptr<std::vector<std::unique_ptr<Aspect>>> aspects);

    std::unique_ptr<Lattice> manifest(int tick) override;

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_OVERLAPAFFINITY_H
