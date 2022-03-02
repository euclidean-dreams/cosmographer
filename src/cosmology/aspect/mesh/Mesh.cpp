#include "Mesh.h"

namespace cosmographer {

Mesh::Mesh(
        AspectCommunity *community,
        int glimmerCount
) :
        Liaison<MeshCommunity>(community) {
    auto latticeSize = community->paradigm->latticeHeight * community->paradigm->latticeWidth;
    float placingIncrement = cast(float, latticeSize) / glimmerCount;
    for (int signalIndex = 0; signalIndex < glimmerCount; signalIndex++) {
        auto latticeIndex = placingIncrement * signalIndex;
        auto latticePoint = CLOISTER->cartographer->verticalWrap(latticeIndex);
        auto lumion = mkup<Lumion>(signalIndex, latticePoint);
        lumion->initialize(&subCommunity);
        subCommunity.lumions.push_back(mv(lumion));
    }
}

void Mesh::meld(
        vec<float> &signal
) {
    for (auto &lumion: subCommunity.lumions) {
        auto excitation = lumion->excite(signal);
        if (excitation.magnitude > 0.1) {
            community->glimmering->excite(excitation);
        }
    }
}

}
