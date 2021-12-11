#include "Plumage.h"

namespace cosmographer {

Plumage::Plumage()
        : ephemera{},
          colorium{std::make_unique<JourneyColorium>(PARADIGM.getLatticeWidth() * PARADIGM.getLatticeHeight())} {

}

std::unique_ptr<Lattice> Plumage::manifest(int tick) {
    auto lattice = std::make_unique<Lattice>();
    EphemeraEcosystem::trim(ephemera, MAX_EPHEMERA);
    EphemeraEcosystem::observe(ephemera, *lattice);
    return lattice;
}

void Plumage::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    colorium->experiencePhenomenon(phenomenon);
}

void Plumage::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    colorium->experienceEssentia(essentia);
    auto spawnIndices = EphemeraEcosystem::determineSpawnIndices(essentia, SPAWN_FACTOR);
    for (auto &index: spawnIndices) {
        auto bloom = std::make_unique<Bloom>(CoordinateTransformer::verticalWrap(index), colorium->getColor(index));
        ephemera.push_back(move(bloom));
    }
}

}
