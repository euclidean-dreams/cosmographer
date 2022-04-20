#include "Lumion.h"
#include "cosmology/aspect/revealery/Revealery.h"

namespace cosmographer {

Lumion::Lumion(
        AspectCommunity *aspectCommunity,
        int signalIndex,
        Point latticePoint
) :
        aspectCommunity{aspectCommunity},
        signalIndex{signalIndex},
        latticePoint{latticePoint} {

}

void Lumion::excite(
        Signal &signal
) {
    // calculate excitation
    auto targetSample = signal.getSample(signalIndex);

    // proportion of signal
//    auto excitation = targetSample / signal.energy;

    // brute threshold
//    auto excitation = 1 - 1 / (std::pow(targetSample / (-1 * (10000 - 9950 * LUMION_EXCITATION_AXIOM)), 2) + 1);

    // just gimmie that friggan valuuuuue! And cap it!
    auto magnitude = targetSample;
    if (magnitude > 1) {
        magnitude = 1;
    }

    // float around
    // takes some serious compute
//    auto distance = -excitation * LUMION_DRIFT;
//    auto direction = CLOISTER->randomizer->generateProportion() * 2 * M_PI;
//    auto potentialNewLatticePoint = CLOISTER->cartographer->shiftPoint(latticePoint, distance, direction);
//    if (CLOISTER->cartographer->isValid(potentialNewLatticePoint)) {
//        latticePoint = potentialNewLatticePoint;
//    }

    if (magnitude > LUMION_EXCITATION_THRESHOLD_AXIOM) {
        auto excitation = LumionExcitation{
                latticePoint,
                signalIndex,
                cast(float, magnitude),
                cast(float, signal.energy)
        };

        aspectCommunity->revealeries[paradigm->macroMode]->reveal(excitation);
    }
}

}
