#include "Aspect.h"
#include "cosmology/aspect/revealery/WorkshopRevealery.h"
#include "cosmology/aspect/revealery/OrbRevealery.h"
#include "cosmology/aspect/revealery/SpectrumRevealery.h"

namespace cosmographer {

Aspect::Aspect(
        CosmologyCommunity *community
) :
        Liaison<AspectCommunity>(community) {
    subCommunity.mesh = mkup<Mesh>(&subCommunity, CONSTANTS->lumionCount);
    subCommunity.mesh->initialize(&subCommunity);
    subCommunity.revealeries.push_back(mkup<WorkshopRevealery>());
    subCommunity.revealeries.push_back(mkup<SpectrumRevealery>());
    subCommunity.revealeries.push_back(mkup<OrbRevealery>());
    subCommunity.revealeries.push_back(mkup<WorkshopRevealery>());
    subCommunity.revealeries.push_back(mkup<WorkshopRevealery>());
    for (auto &revealery: subCommunity.revealeries) {
        revealery->initialize(&subCommunity);
    }
    subCommunity.glimmering = mkup<Glimmering>(&subCommunity);
    subCommunity.glimmering->initialize(&subCommunity);
}

void Aspect::manifest(
        Lattice &lattice
) {
    subCommunity.glimmering->illuminate(lattice);
}

void Aspect::experienceEssentia() {
    for (auto &revealery: subCommunity.revealeries) {
        revealery->experienceSignal();
    }
    subCommunity.mesh->meld();
}

}
