#ifndef COSMOGRAPHER_PLUMAGE_H
#define COSMOGRAPHER_PLUMAGE_H

#include "Aspect.h"
#include "cosmology/ephemera/Bloom.h"
#include "gizmo/color/colorium/JourneyColorium.h"

namespace cosmographer {

class Plumage : public Aspect {
private:
    const int maxEphemera = 300;
    std::list<std::unique_ptr<Bloom>> ephemera;
    std::unique_ptr<Colorium> colorium;
    float scale;
    float spawnFactor;

public:
    Plumage(float scale, float spawnFactor);

    std::unique_ptr<Lattice> manifest(int tick) override;

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_PLUMAGE_H
