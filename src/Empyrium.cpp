#include "Empyrium.h"

namespace cosmographer {

Empyrium::Empyrium(std::shared_ptr<Cosmology> cosmology)
        : cosmology{move(cosmology)},
          tickInterval{EMPYRIUM_TICK_INTERVAL} {

}

void Empyrium::activate() {
    Paradigm::getInstance().refresh();
    cosmology->alter();
}

uint64_t Empyrium::getTickInterval() {
    return tickInterval;
}

bool Empyrium::finished() {
    return cosmology->isConcluded();
}

}
