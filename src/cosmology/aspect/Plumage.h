#ifndef COSMOGRAPHER_PLUMAGE_H
#define COSMOGRAPHER_PLUMAGE_H

#include "Aspect.h"
#include "cosmology/ephemera/Bloom.h"
#include "gizmo/color/colorium/JourneyColorium.h"

#define SPAWN_FACTOR 300
#define MAX_EPHEMERA 2000

namespace cosmographer {

class Plumage : public Aspect {
private:
    std::list<std::unique_ptr<Bloom>> ephemera;
    std::unique_ptr<Colorium> colorium;

public:
    Plumage();

    std::unique_ptr<Lattice> manifest(int tick) override;

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;
};

}

#endif //COSMOGRAPHER_PLUMAGE_H
