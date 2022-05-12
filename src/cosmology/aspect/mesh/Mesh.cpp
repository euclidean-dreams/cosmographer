#include "Mesh.h"

namespace cosmographer {

Mesh::Mesh(
        AspectCommunity *community,
        int lumionCount
) :
        Liaison<MeshCommunity>(community) {

    // glimmer_placement in desmos
    auto latticeSize = CONSTANTS->percipiaHeight * CONSTANTS->percipiaWidth;
//    auto L = latticeSize;
//    auto G = lumionCount;
//    auto a = CONSTANTS->lumionPlacement * lumionCount;
//    auto b = G / (std::exp(L / a) - 1);

    for (int lumionIndex = 0; lumionIndex < lumionCount; lumionIndex++) {
        auto x = lumionIndex;
//        auto latticeIndex = a * std::log(1 + x / b);
//        auto latticePoint = CLOISTER->cartographer->verticalWrap(latticeIndex);
        auto latticePoint = Point{cast(float, CONSTANTS->percipiaWidth / 2), cast(float, CONSTANTS->percipiaHeight / 2)};
        auto lumion = mkup<Lumion>(community, lumionIndex, latticePoint);
        lumion->initialize(&subCommunity);
        subCommunity.lumions.push_back(mv(lumion));
    }

//    for (int lumionIndex = 0; lumionIndex < lumionCount; lumionIndex++) {
//        auto latticePoint = Point{
//                CLOISTER->randomizer->generateProportion() * CONSTANTS->latticeWidth,
//                CLOISTER->randomizer->generateProportion() * CONSTANTS->latticeHeight
//        };
//        auto lumion = mkup<Lumion>(lumionIndex, latticePoint);
//        lumion->initialize(&subCommunity);
//        subCommunity.lumions.push_back(mv(lumion));
//    }
}

void Mesh::meld() {
    for (auto &lumion: subCommunity.lumions) {
        lumion->react();
    }
}

}
