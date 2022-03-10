#include "Mesh.h"

namespace cosmographer {

Mesh::Mesh(
        AspectCommunity *community,
        int lumionCount
) :
        Liaison<MeshCommunity>(community) {
    auto latticeSize = CONSTANTS->latticeHeight * CONSTANTS->latticeWidth;

    // glimmer_placement in desmos
    auto L = latticeSize;
    auto G = lumionCount;
    auto a = CONSTANTS->lumionPlacement * lumionCount;
    auto b = G / (std::exp(L / a) - 1);

    for (int lumionIndex = 0; lumionIndex < lumionCount; lumionIndex++) {
        auto x = lumionIndex;
        auto latticeIndex = a * std::log(1 + x / b);
        auto latticePoint = CLOISTER->cartographer->verticalWrap(latticeIndex);
        auto lumion = mkup<Lumion>(lumionIndex, latticePoint);
        lumion->initialize(&subCommunity);
        subCommunity.lumions.push_back(mv(lumion));
    }
}

void Mesh::meld(
        vec<float> &signal
) {
    for (auto &lumion: subCommunity.lumions) {
        auto excitation = lumion->excite(signal);
        if (excitation.magnitude > 0.2) {
            community->revealery->reveal(excitation);
        }
    }
}

}
