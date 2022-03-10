#include "Drift.h"

namespace cosmographer {

Drift::Drift(
        float inclinationOffset
) :
        inclinationOffset{inclinationOffset} {

}

void Drift::live() {
    auto pole = EPHEMERA_AXIOM_0 * 2 * M_PI;
    auto direction = inclinationOffset * 2 * M_PI + pole;
    auto distance = EPHEMERA_AXIOM_1 * CONSTANTS->maxDriftDistance;
    community->locus = CLOISTER->cartographer->shiftPoint(community->locus, distance, direction);
}

}
