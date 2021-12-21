#ifndef COSMOGRAPHER_DRAGONARIUM_H
#define COSMOGRAPHER_DRAGONARIUM_H

#include "Aspect.h"
#include "cosmology/ephemera/Bloom.h"
#include "gizmo/color/colorium/JourneyColorium.h"
#include "cosmology/ephemera/DragonRoar.h"

namespace cosmographer {

class Dragonarium : public Aspect {
private:
    const int maxEphemera = 100;
    const int maxNewEphemera = 5;
    std::list<std::unique_ptr<DragonRoar>> ephemera;
    std::unique_ptr<Colorium> colorium;
    float spawnFactor;

public:
    explicit Dragonarium(float spawnFactor);

    std::unique_ptr<Lattice> manifest(int tick) override;

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_DRAGONARIUM_H
