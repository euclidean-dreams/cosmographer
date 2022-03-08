#include "Glimmer.h"

namespace cosmographer {

Glimmer::Glimmer(
        Paradigm *paradigm,
        up<Illuminable> illuminable,
        Point locus,
        HSLColor color,
        float size
) :
        Liaison<GlimmerCommunity>(paradigm) {
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
    subCommunity.age++;
    for (auto &ephemera: subCommunity.ephemera) {
        ephemera->live();
    }
    subCommunity.illuminable->illuminate(lattice);
    for (auto &terminus: subCommunity.termini) {
        if (terminus->shouldTerminate()) {
            // returns false if dead
            return false;
        }
    }
    return true;
}

void Glimmer::addTerminus(
        up<Terminus> terminus
) {
    terminus->initialize(&subCommunity);
    subCommunity.termini.push_back(mv(terminus));
}

void Glimmer::addEphemera(
        up<Ephemera> ephemera
) {
    ephemera->initialize(&subCommunity);
    subCommunity.ephemera.push_back(mv(ephemera));
}

}
