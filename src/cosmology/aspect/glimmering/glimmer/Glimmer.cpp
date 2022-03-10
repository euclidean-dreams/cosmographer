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

void Glimmer::live() {
    subCommunity.age++;
    for (auto &ephemera: subCommunity.ephemera) {
        ephemera->live();
    }
}

bool Glimmer::shouldTerminate() {
    for (auto &terminus: subCommunity.termini) {
        if (terminus->shouldTerminate()) {
            return true;
        }
    }
    return false;
}

void Glimmer::illuminate(
        Lattice &lattice
) {
    // this should not touch anything outside the glimmer for thread safety
    subCommunity.illuminable->illuminate(lattice);
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
