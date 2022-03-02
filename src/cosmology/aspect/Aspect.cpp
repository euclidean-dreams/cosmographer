#include "Aspect.h"

namespace cosmographer {

Aspect::Aspect(
        CosmologyCommunity *community
) :
        Liaison<AspectCommunity>(community) {
    subCommunity.mesh = mkup<Mesh>(&subCommunity, LUMION_COUNT);
    subCommunity.mesh->initialize(&subCommunity);
    auto revealery = mkup<CircleRevealery>();
    subCommunity.glimmering = mkup<Glimmering>(&subCommunity, mv(revealery));
    subCommunity.glimmering->initialize(&subCommunity);
}

up<Lattice> Aspect::manifest() {
    auto lattice = mkup<Lattice>(community->paradigm->latticeWidth, community->paradigm->latticeHeight);
    subCommunity.glimmering->illuminate(*lattice);
    return lattice;
}

void Aspect::experienceEssentia(const Essentia *essentia) {
    std::vector<float> signal{};
    auto samples = essentia->melSignal();
    signal.reserve(samples->size());
    for (int index = 0; index < samples->size(); index++) {
        if (index < samples->size()) {
            signal.push_back(samples->Get(index));
        } else {
            signal.push_back(0);
        }
    }
    subCommunity.mesh->meld(signal);
}

}
