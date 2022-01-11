#include "EphemeraEcosystem.h"

namespace cosmographer {

std::vector<int> EphemeraEcosystem::determineSpawnIndices(const ImpresarioSerialization::Essentia *essentia,
                                                          float spawnFactor) {
    std::vector<int> result{};
    auto samples = essentia->radixes();
    auto normalizationScale = AXIOMOLOGY.getEphemeraNormalizationScale();
    auto spawnThreshold = AXIOMOLOGY.getEphemeraSpawnThreshold();
    for (int index = 0; index < samples->size(); index++) {
        auto sample = samples->Get(index);

        // due to mel filterbank overflow, that last triangular filter catches everything above it
        // accommodate for crazy large last sample - this will go once those ridiculous triangular filters are changed
        if (index == samples->size() - 1) {
            sample /= 100;
        }

        // normalize
        auto normalizedSample = 1 - 1 / (std::pow(sample / (-1 * (1000 - 1000 * normalizationScale)), 2) + 1);

        if (normalizedSample > 1 - spawnThreshold) {
            result.push_back(index);
        }
    }
    return result;
}

}
