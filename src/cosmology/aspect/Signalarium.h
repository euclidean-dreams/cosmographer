#ifndef COSMOGRAPHER_SIGNALARIUM_H
#define COSMOGRAPHER_SIGNALARIUM_H

#include "Aspect.h"
#include "cosmology/illuminable/Signal.h"
#include "gizmo/color/colorium/JourneyColorium.h"


namespace cosmographer {

class Signalarium : public Aspect {
private:
    std::unique_ptr<Signal> signal;
    std::unique_ptr<Colorium> colorium;

public:
    Signalarium();

    std::unique_ptr<Lattice> manifest(int tick) override;

    void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) override;

    void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) override;

};

}

#endif //COSMOGRAPHER_SIGNALARIUM_H
