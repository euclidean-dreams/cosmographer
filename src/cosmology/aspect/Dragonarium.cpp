#include "Dragonarium.h"

namespace cosmographer {

Dragonarium::Dragonarium(float spawnFactor)
        : ephemera{},
          colorium{std::make_unique<JourneyColorium>(PARADIGM.getLatticeWidth() * PARADIGM.getLatticeHeight())},
          spawnFactor{spawnFactor} {
}

std::unique_ptr<Lattice> Dragonarium::manifest(int tick) {
    auto lattice = std::make_unique<Lattice>();
    EphemeraEcosystem::trim(ephemera, maxEphemera);
    EphemeraEcosystem::observe(ephemera, *lattice);
    return lattice;
}

void Dragonarium::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    colorium->experiencePhenomenon(phenomenon);
}

void Dragonarium::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    colorium->experienceEssentia(essentia);
    auto spawnIndices = EphemeraEcosystem::determineSpawnIndices(essentia, spawnFactor);

    // TODO remove once lindogram caching is implemented
    while (spawnIndices.size() > maxNewEphemera) {
        spawnIndices.pop_back();
    }

    for (auto &index: spawnIndices) {
        auto dragonRoar = std::make_unique<DragonRoar>(CoordinateTransformer::verticalWrap(index),
                                                       colorium->getColor(index));
        ephemera.push_back(move(dragonRoar));
    }
}

}
