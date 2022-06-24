#include "Lumion.h"
#include "oddments/Tidbit.h"
#include "cosmology/aspect/revealery/Revealery.h"

namespace cosmographer {

Lumion::Lumion(
        AspectCommunity *aspectCommunity,
        int firstIndexToWatch,
        int lastIndexToWatch,
        Point latticePoint
) :
        aspectCommunity{aspectCommunity},
        firstIndexToWatch{firstIndexToWatch},
        lastIndexToWatch{lastIndexToWatch},
        latticePoint{latticePoint},
        color{0, 0, 0} {
    color = chromatica->getColor();
}

void Lumion::react() {
    // calculate excitation
    auto &signal = signalarium->stft;
    magnitude = 0;
    for (int index = firstIndexToWatch; index < lastIndexToWatch; index++) {
        auto indexValue = signal.getSample(index);
        if (indexValue > magnitude) {
            magnitude = indexValue;
        }
//        magnitude += signal.getSample(index);
    }

    // proportion of signal
//    auto excitation = targetSample / signal.energy;

    // brute threshold
//    auto excitation = 1 - 1 / (std::pow(targetSample / (-1 * (10000 - 9950 * LUMION_EXCITATION_AXIOM)), 2) + 1);

    // just gimmie that friggan value! And cap it!
//    magnitude = Tidbit::bind(targetSample, 0.0, 1.0);
    auto excitationThreshold = LUMION_EXCITATION_THRESHOLD_AXIOM * 75;

    if (excited) {
        // float around
//        auto distance = magnitude / 75 * MOVEMENT_AXIOM;
//        auto direction = randomizer->generateProportion() * 2 * M_PI;
//        auto potentialNewLatticePoint = cartographer->shiftPoint(latticePoint, distance, direction);
//        if (cartographer->isValid(potentialNewLatticePoint)) {
//            latticePoint = potentialNewLatticePoint;
//        }
        if (magnitude < excitationThreshold / 8) {
            excited = false;
        }
    } else if (magnitude > excitationThreshold) {
//        LOGGER->info(magnitude);
        // the flip
        excited = true;
        lumionBookie->recordActivation(magnitude);
        color = chromatica->getColor();
    }

    if (excited) {
        // make some glimmers
        color.lightness = magnitude;
        aspectCommunity->revealeries[macroMode]->reveal(this);
    } else {
        if (centerMode) {
            center();
        }
    }
}

void Lumion::center() {
    latticePoint = {cast(float, constants->percipiaWidth / 2), cast(float, constants->percipiaHeight / 2)};
}

}
