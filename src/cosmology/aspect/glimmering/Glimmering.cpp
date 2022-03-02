#include "Glimmering.h"

namespace cosmographer {

Glimmering::Glimmering(
        AspectCommunity *community,
        up<Revealery> revealery
) :
        Liaison<GlimmeringCommunity>(community) {
    subCommunity.revealery = mv(revealery);
    subCommunity.revealery->initialize(&subCommunity);
}

void Glimmering::excite(
        LumionExcitation excitation
) {
    subCommunity.revealery->reveal(excitation);
}

void Glimmering::illuminate(
        Lattice &lattice
) {
    auto iterator = subCommunity.glimmers.begin();
    while (iterator != subCommunity.glimmers.end()) {
        auto isAlive = (*iterator)->illuminate(lattice);
        if (isAlive) {
            iterator++;
        } else {
            iterator = subCommunity.glimmers.erase(iterator);
        }
    }

}

}
