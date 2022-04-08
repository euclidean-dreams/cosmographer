#include "RandomWalk.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/lindogram/Painter.h"

namespace cosmographer {

RandomWalk::RandomWalk(
        Paradigm *paradigm,
        float orientation,
        float spin
) :
        Liaison<LindogramCommunity>(paradigm),
        spin{spin} {
    subCommunity.canvas = mkup<Canvas>();
    subCommunity.canvas->initialize(&subCommunity);
    subCommunity.painter = mkup<Painter>();
    subCommunity.painter->initialize(&subCommunity);
    subCommunity.painter->rotate(orientation);
}

void RandomWalk::illuminate(Lattice &lattice) {
    subCommunity.painter->advance(1, community->color);
    subCommunity.painter->advance(1, community->color);
    subCommunity.painter->rotate(spin / community->age);
    Coordinate locus{cast(int, community->locus.x), cast(int, community->locus.y)};
    subCommunity.canvas->show(lattice, locus);
}

}
