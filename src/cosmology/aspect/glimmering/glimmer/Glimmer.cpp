#include "Glimmer.h"

namespace cosmographer {

void Glimmer::live() {
    for (auto &lively: livelies) {
        lively->live();
    }
}

bool Glimmer::shouldTerminate() {
    for (auto &terminable: terminbles) {
        if (terminable->shouldTerminate()) {
            return true;
        }
    }
    return false;
}

void Glimmer::illuminate(
        Lattice &lattice
) {
    // this should not touch anything outside the glimmer for thread safety
    for (auto &illuminable: illuminables) {
        illuminable->illuminate(lattice);
    }
}

}
