#include "Drift.h"

namespace cosmographer {

Drift::Drift(
        float inclinationOffset
) :
        inclinationOffset{inclinationOffset} {

}

void Drift::live() {
    auto pole = EPHEMERA_AXIOM_0 * 2 * M_PI;
    auto driftAngle = inclinationOffset * 2 * M_PI + pole;
    auto driftDistance = EPHEMERA_AXIOM_1 * MAX_DRIFT_DISTANCE;
    community->locus = CLOISTER->cartographer->shiftPoint(community->locus, driftDistance, driftAngle);
}

}
