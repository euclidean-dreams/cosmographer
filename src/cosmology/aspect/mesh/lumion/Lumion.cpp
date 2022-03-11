#include "Lumion.h"

namespace cosmographer {

Lumion::Lumion(
        int signalIndex,
        Point latticePoint
) :
        signalIndex{signalIndex},
        latticePoint{latticePoint} {

}

LumionExcitation Lumion::excite(
        vec<float> &signal
) {
    // calculate excitation
    auto normalizationScale = LUMION_EXCITATION_AXIOM;
    auto sample = signal[signalIndex];
    auto excitation = 1 - 1 / (std::pow(sample / (-1 * (10000 - 9950 * normalizationScale)), 2) + 1);

    // float around
    auto distance = - excitation * LUMION_DRIFT;
    auto direction = CLOISTER->randomizer->generateProportion() * 2 * M_PI;
    auto potentialNewLatticePoint = CLOISTER->cartographer->shiftPoint(latticePoint, distance, direction);
    if(CLOISTER->cartographer->isValid(potentialNewLatticePoint)) {
        latticePoint = potentialNewLatticePoint;
    }

    return LumionExcitation{
            latticePoint,
            cast(float, excitation)
    };
}

}
