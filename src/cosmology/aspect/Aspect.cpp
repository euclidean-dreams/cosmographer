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
    subCommunity.revealeries.push_back(mkup<OrbRevealery>());
    subCommunity.revealeries.push_back(mkup<SpectrumRevealery>());
    subCommunity.revealeries.push_back(mkup<OrbRevealery>());
    subCommunity.revealeries.push_back(mkup<OrbRevealery>());
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

void Aspect::experienceEssentia(
        const Essentia *essentia
) {
    auto samples = essentia->stft();
    Signal signal{static_cast<int>(samples->size())};
    for (int index = 0; index < samples->size(); index++) {
        auto sample = samples->Get(index);
        signal.addSample(sample);
    }
    subCommunity.mesh->meld(signal);
    for (auto &revealery: subCommunity.revealeries) {
        revealery->experienceSignal(signal);
    }
}

}
