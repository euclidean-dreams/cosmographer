#include "Glimmering.h"

namespace cosmographer {

Glimmering::Glimmering(
        AspectCommunity *community
) :
        Liaison<GlimmeringCommunity>(community) {
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

void Glimmering::addGlimmer(
        up<Glimmer> glimmer
) {
    glimmer->initialize(&subCommunity);
    subCommunity.glimmers.push_back(mv(glimmer));
}

}
