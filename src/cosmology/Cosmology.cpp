#include "Cosmology.h"
#include "cosmology/aspect/revealery/WorkshopRevealery.h"

namespace cosmographer {

Cosmology::Cosmology(
        CosmographerCommunity *community
) :
        Liaison<CosmologyCommunity>(community) {
    auto revealery = mkup<WorkshopRevealery>();
    subCommunity.aspect = mkup<Aspect>(&subCommunity, mv(revealery));
    subCommunity.aspect->initialize(&subCommunity);
}

void Cosmology::observe() {
    auto lattice = mkup<Lattice>(CONSTANTS->latticeWidth, CONSTANTS->latticeHeight, CONSTANTS->latticeInitialColor);
    subCommunity.aspect->manifest(*lattice);
    community->vantage->send(*lattice);
}

void Cosmology::experienceEssentia(const Essentia *essentia) {
    subCommunity.aspect->experienceEssentia(essentia);
}

}
