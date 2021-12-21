#ifndef COSMOGRAPHER_BURSTING_H
#define COSMOGRAPHER_BURSTING_H

#include "Aspect.h"
#include "cosmology/ephemera/Burst.h"
#include "gizmo/color/colorium/JourneyColorium.h"

namespace cosmographer {

class Bursting : public Aspect {
private:
    const int maxEphemera = 100;
    std::list<std::unique_ptr<Burst>> ephemera;
    std::unique_ptr<Colorium> colorium;
    float scale;
    float spawnFactor;

public:
    Bursting(float scale, float spawnFactor);

    std::unique_ptr<Lattice> manifest(int tick) override;

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_BURSTING_H
