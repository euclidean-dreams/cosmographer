#include "Glimmer.h"

namespace cosmographer {

Glimmer::Glimmer(
        Paradigm *paradigm,
        up<Ephemera> ephemera,
        up<Illuminable> illuminable,
        Point locus,
        HSLColor color,
        float size
) :
        Liaison<GlimmerCommunity>(paradigm) {
    subCommunity.ephemera = mv(ephemera);
    subCommunity.ephemera->initialize(&subCommunity);
    subCommunity.illuminable = mv(illuminable);
    subCommunity.illuminable->initialize(&subCommunity);
    subCommunity.locus = locus;
    subCommunity.color = color;
    subCommunity.size = size;
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
