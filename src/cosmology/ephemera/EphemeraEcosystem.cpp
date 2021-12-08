#include "EphemeraEcosystem.h"

namespace cosmographer {

void EphemeraEcosystem::add(std::unique_ptr<Ephemera> ephemera) {
    ecosystem.push_back(move(ephemera));
}

void EphemeraEcosystem::observe(Lattice &lattice) {
    auto iterator = ecosystem.begin();
    while (iterator != ecosystem.end()) {
        if ((*iterator)->isDead()) {
            iterator = ecosystem.erase(iterator);
        } else {
            (*iterator)->live(lattice);
            (*iterator)->incrementAge();
            iterator++;
        }
    }
}

}
