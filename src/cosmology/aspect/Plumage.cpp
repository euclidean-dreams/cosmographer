#include "Plumage.h"

namespace cosmographer {

Plumage::Plumage(float scale, float spawnFactor)
        : ephemera{},
          colorium{std::make_unique<JourneyColorium>(PARADIGM.getLatticeWidth() * PARADIGM.getLatticeHeight())},
          scale{scale},
          spawnFactor{spawnFactor} {

}

std::unique_ptr<Lattice> Plumage::manifest(int tick) {
    auto lattice = std::make_unique<Lattice>();
    EphemeraEcosystem::trim(ephemera, maxEphemera);
    EphemeraEcosystem::observe(ephemera, *lattice);
    return lattice;
}

void Plumage::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    colorium->experiencePhenomenon(phenomenon);
}

void Plumage::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    colorium->experienceEssentia(essentia);
    auto spawnIndices = EphemeraEcosystem::determineSpawnIndices(essentia, spawnFactor);

    for (auto &index: spawnIndices) {
        auto bloom = std::make_unique<Bloom>(CoordinateTransformer::verticalWrap(index), colorium->getColor(index),
                                             scale);
        ephemera.push_back(move(bloom));
    }
}

}
