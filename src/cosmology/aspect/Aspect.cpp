#include "Aspect.h"

namespace cosmographer {

Aspect::Aspect(
        CosmologyCommunity *community,
        up<Revealery> revealery
) :
        Liaison<AspectCommunity>(community) {
    subCommunity.mesh = mkup<Mesh>(&subCommunity, CONSTANTS->lumionCount);
    subCommunity.mesh->initialize(&subCommunity);
    subCommunity.revealery = mv(revealery);
    subCommunity.revealery->initialize(&subCommunity);
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
}

}
