#include "EphemeraEcosystem.h"

namespace cosmographer {

std::vector<int> EphemeraEcosystem::determineSpawnIndices(const ImpresarioSerialization::Essentia *essentia,
                                                          float spawnFactor) {
    std::vector<int> result{};
    auto samples = essentia->lagFlux();
    for (int index = 0; index < samples->size(); index++) {
        auto sample = samples->Get(index);

        // due to mel filterbank overflow, that last triangular filter catches everything above it
        // accommodate for crazy large last sample - this will go once those ridiculous triangular filters are changed
        if (index == samples->size() - 1) {
            sample /= 100;
        }

        auto magnitude = AXIOMOLOGY->getMagnitude();
        auto threshold = spawnFactor - magnitude * spawnFactor;
        if (sample > threshold) {
            result.push_back(index);
        }
    }
    return result;
}

}
