#include "Cosmology.h"
#include "cosmology/aspect/revealery/BrushPartyRevealery.h"

namespace cosmographer {

Cosmology::Cosmology(
        CosmographerCommunity *community
) :
        Liaison<CosmologyCommunity>(community) {
    auto revealery = mkup<BrushPartyRevealery>();
    subCommunity.aspect = mkup<Aspect>(&subCommunity, mv(revealery));
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
