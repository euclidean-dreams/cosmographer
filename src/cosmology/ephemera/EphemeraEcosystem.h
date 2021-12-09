#ifndef COSMOGRAPHER_EPHEMERAECOSYSTEM_H
#define COSMOGRAPHER_EPHEMERAECOSYSTEM_H

#include "cosmology/ephemera/Ephemera.h"

namespace cosmographer {

class EphemeraEcosystem {
public:
    template<typename T>
    static void trim(std::list<std::unique_ptr<T>> &ephemera, int maxEphemera) {
        while (ephemera.size() > maxEphemera) {
            ephemera.pop_front();
        }
    }

    template<typename T>
    static void observe(std::list<std::unique_ptr<T>> &ephemera, Lattice &lattice) {
        auto iterator = ephemera.begin();
        while (iterator != ephemera.end()) {
            if ((*iterator)->isDead()) {
                iterator = ephemera.erase(iterator);
            } else {
                (*iterator)->live(lattice);
                (*iterator)->incrementAge();
                iterator++;
            }
        }
    }

    static std::vector<int> determineSpawnIndices(const ImpresarioSerialization::Essentia *essentia,
                                                  float spawnFactor);
};

}

#endif //COSMOGRAPHER_EPHEMERAECOSYSTEM_H
