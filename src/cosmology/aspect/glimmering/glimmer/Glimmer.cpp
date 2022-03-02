#include "Glimmer.h"

namespace cosmographer {

Glimmer::Glimmer(
        GlimmeringCommunity *community,
        up<Ephemera> ephemera,
        up<Illuminable> illuminable,
        Point locus,
        HSLColor color
) :
        Liaison<GlimmerCommunity>(community) {
    subCommunity.ephemera = mv(ephemera);
    subCommunity.ephemera->initialize(&subCommunity);
    subCommunity.illuminable = mv(illuminable);
    subCommunity.illuminable->initialize(&subCommunity);
    subCommunity.locus = locus;
    subCommunity.color = color;
    subCommunity.age = 0;
}

bool Glimmer::illuminate(
        Lattice &lattice
) {
    subCommunity.ephemera->live();
    subCommunity.illuminable->illuminate(lattice);

    // returns false if dead
    return subCommunity.ephemera->isAlive();
}

}
