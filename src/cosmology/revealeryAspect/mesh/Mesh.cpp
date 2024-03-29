#include <complex.h>
#include "Mesh.h"

namespace cosmographer {

Mesh::Mesh(
        RevealeryAspectCommunity *community
) :
        Liaison<MeshCommunity>(community) {

//    // glimmer_placement in desmos
//    auto latticeSize = constants->percipiaHeight * constants->percipiaWidth;
//    auto L = latticeSize;
//    auto G = lumionCount;
//    auto a = constants->lumionPlacement * lumionCount;
//    auto b = G / (std::exp(L / a) - 1);
//    -----------------------------------
//    auto latticeCenter = Point{cast(float, constants->percipiaWidth) / 2, cast(float, constants->percipiaHeight) / 2};
    auto lumionSpan = Config::getInstance().getInt("essentiaSize") / constants->lumionCount;
    for (int lumionIndex = 0; lumionIndex < constants->lumionCount; lumionIndex++) {
        auto firstIndex = lumionIndex * lumionSpan;
        auto lastIndex = firstIndex + lumionSpan;
        auto lumion = mkup<Lumion>(community, lumionIndex, firstIndex, lastIndex);
        lumion->initialize(&subCommunity);
        subCommunity.lumions.push_back(mv(lumion));
    }

}

void Mesh::meld() {
    for (auto &lumion: subCommunity.lumions) {
        lumion->react();
    }
}

}
