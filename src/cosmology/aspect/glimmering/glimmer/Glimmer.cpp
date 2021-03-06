#include "Glimmer.h"

namespace cosmographer {

Glimmer::Glimmer(
        GlimmeringCommunity *glimmeringCommunity,
        up<GlimmerSoul> glimmerSoulWrapper
) :
        glimmerSoul{glimmerSoulWrapper.get()} {
    initialize(glimmeringCommunity);
    constituents.push_back(mv(glimmerSoulWrapper));
}

void Glimmer::live() {
    for (auto &lively: livelies) {
        lively->live();
    }
    glimmerSoul->age++;
}

bool Glimmer::shouldTerminate() {
    return !glimmerSoul->alive;
}

void Glimmer::illuminate(
        Lattice &lattice
) {
    // this should not touch anything outside the glimmer for thread safety
    for (auto &illuminable: illuminables) {
        illuminable->illuminate(lattice);
    }
}

void Glimmer::addLively(up<Lively> lively) {
    livelies.push_back(lively.get());
    constituents.push_back(mv(lively));
}

void Glimmer::addIlluminable(up<Illuminable> illuminable) {
    illuminables.push_back(illuminable.get());
    constituents.push_back(mv(illuminable));
}

}
