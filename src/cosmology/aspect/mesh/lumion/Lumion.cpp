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
        Signal &signal
) {
    // calculate excitation
    auto targetSample = signal.getSample(signalIndex);

    // proportion of signal
//    auto excitation = targetSample / signal.energy;

    // brute threshold
//    auto excitation = 1 - 1 / (std::pow(targetSample / (-1 * (10000 - 9950 * LUMION_EXCITATION_AXIOM)), 2) + 1);

    // just gimmie that friggan valuuuuue! And cap it!
    auto excitation = targetSample / 1000;
    if (excitation > 1) {
        excitation = 1;
    }

    // float around
    // takes some serious compute
//    auto distance = -excitation * LUMION_DRIFT;
//    auto direction = CLOISTER->randomizer->generateProportion() * 2 * M_PI;
//    auto potentialNewLatticePoint = CLOISTER->cartographer->shiftPoint(latticePoint, distance, direction);
//    if (CLOISTER->cartographer->isValid(potentialNewLatticePoint)) {
//        latticePoint = potentialNewLatticePoint;
//    }

    return LumionExcitation{
            latticePoint,
            signalIndex,
            cast(float, excitation),
            cast(float, signal.energy)
    };
}

}
