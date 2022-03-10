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
    std::vector<float> signal{};
    auto samples = essentia->stft();
    signal.reserve(samples->size());
    for (int index = 0; index < samples->size(); index++) {
        if (index < samples->size()) {
            auto sample = samples->Get(index);
            signal.push_back(sample);
        } else {
            signal.push_back(0);
        }
    }
    subCommunity.mesh->meld(signal);
}

}
