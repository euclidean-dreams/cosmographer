#include "Lumion.h"
#include "oddments/Tidbit.h"
#include "cosmology/aspect/revealery/Revealery.h"

namespace cosmographer {

Lumion::Lumion(
        AspectCommunity *aspectCommunity,
        int signalIndex,
        Point latticePoint
) :
        aspectCommunity{aspectCommunity},
        signalIndex{signalIndex},
        latticePoint{latticePoint},
        hue{} {
//    center();
}

void Lumion::react() {
    // calculate excitation
    auto &signal = CLOISTER->signalarium->equalized;
    auto targetSample = signal.getSample(signalIndex);

    // proportion of signal
//    auto excitation = targetSample / signal.energy;

    // brute threshold
//    auto excitation = 1 - 1 / (std::pow(targetSample / (-1 * (10000 - 9950 * LUMION_EXCITATION_AXIOM)), 2) + 1);

    // just gimmie that friggan value! And cap it!
    magnitude = Tidbit::bind(targetSample, 0.0, 1.0);

    if (excited) {
        // float around
        // takes some serious compute
        auto distance = 10 * magnitude * MOVEMENT_AXIOM;
        auto direction = CLOISTER->randomizer->generateProportion() * 2 * M_PI;
        auto potentialNewLatticePoint = CLOISTER->cartographer->shiftPoint(latticePoint, distance, direction);
        if (CLOISTER->cartographer->isValid(potentialNewLatticePoint)) {
            latticePoint = potentialNewLatticePoint;
        }
        if (magnitude < LUMION_EXCITATION_THRESHOLD_AXIOM / 32) {
            excited = false;
//            center();
        }
    } else if (magnitude > LUMION_EXCITATION_THRESHOLD_AXIOM) {
        excited = true;
        CLOISTER->lumionBookie->recordActivation(magnitude);
    }

    if (excited) {
        aspectCommunity->revealeries[paradigm->macroMode]->reveal(this);
    } else {
        // -0.5 <-> 0.5
//        float variance = PALETTE_AXIOM_0 - 0.5;
//        hue += variance * RANDOM.generate(10);

        hue = CLOISTER->chromatica->getColor().hue;
    }
}

void Lumion::center() {
    latticePoint = {cast(float, CONSTANTS->latticeWidth / 2), cast(float, CONSTANTS->latticeHeight / 2)};
}

}
