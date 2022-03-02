#include "Cosmology.h"

namespace cosmographer {

Cosmology::Cosmology(
        CosmographerCommunity *community
) :
        Liaison<CosmologyCommunity>(community) {
    subCommunity.aspect = mkup<Aspect>(&subCommunity);
    subCommunity.aspect->initialize(&subCommunity);
}

void Cosmology::observe() {
    auto lattice = subCommunity.aspect->manifest();
    community->vantage->send(*lattice);
}

void Cosmology::experienceEssentia(const Essentia *essentia) {
    subCommunity.aspect->experienceEssentia(essentia);
}

}
