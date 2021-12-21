#include "Bursting.h"

namespace cosmographer {

Bursting::Bursting(float scale, float spawnFactor)
        : ephemera{},
          colorium{std::make_unique<JourneyColorium>(PARADIGM.getLatticeWidth() * PARADIGM.getLatticeHeight())},
          scale{scale},
          spawnFactor{spawnFactor} {

}

std::unique_ptr<Lattice> Bursting::manifest(int tick) {
    auto lattice = std::make_unique<Lattice>();
    EphemeraEcosystem::trim(ephemera, maxEphemera);
    EphemeraEcosystem::observe(ephemera, *lattice);
    return lattice;
}

void Bursting::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    colorium->experiencePhenomenon(phenomenon);
}

void Bursting::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    colorium->experienceEssentia(essentia);
    auto spawnIndices = EphemeraEcosystem::determineSpawnIndices(essentia, spawnFactor);

    for (auto &index: spawnIndices) {
        auto burst = std::make_unique<Burst>(CoordinateTransformer::verticalWrap(index), colorium->getColor(index),
                                             scale);
        ephemera.push_back(move(burst));
    }
}

}
