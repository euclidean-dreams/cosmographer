#include "Lumion.h"
#include "oddments/Tidbit.h"
#include "cosmology/aspect/revealery/Revealery.h"

namespace cosmographer {

Lumion::Lumion(
        AspectCommunity *aspectCommunity,
        int lumionIndex,
        int firstIndexToWatch,
        int lastIndexToWatch,
        Point latticePoint
) :
        aspectCommunity{aspectCommunity},
        lumionIndex{lumionIndex},
        firstIndexToWatch{firstIndexToWatch},
        lastIndexToWatch{lastIndexToWatch},
        latticePoint{latticePoint} {
    color = chromatica->getColor();
}

void Lumion::react() {
    // calculate excitation
    auto &signal = signalarium->stft;
    magnitude = 0;
    for (int index = firstIndexToWatch; index < lastIndexToWatch; index++) {
//        auto indexValue = signal.getSample(index);
//        if (indexValue > targetSample) {
//            targetSample = indexValue;
//        }
        magnitude += signal.getSample(index);
    }

    // proportion of signal
//    auto excitation = targetSample / signal.energy;

    // brute threshold
//    auto excitation = 1 - 1 / (std::pow(targetSample / (-1 * (10000 - 9950 * LUMION_EXCITATION_AXIOM)), 2) + 1);

    // just gimmie that friggan value! And cap it!
//    magnitude = Tidbit::bind(targetSample, 0.0, 1.0);

    // anything is possible just beyond the reach of a path
    auto stateChangeThresholdMax = constants->excitationThresholdMax;
    auto flippedExcitationAxiom = 1 - EXCITATION_AXIOM;
    if (flippedExcitationAxiom == 0)
        flippedExcitationAxiom = 0.01;
    auto excitationThreshold = flippedExcitationAxiom * stateChangeThresholdMax;

    // scry
    // attempt to figure out what the magnitude one step in the future is going to be based on
    // magnitude of most recent change
    auto signalDeltarivative = magnitude - previousMagnitude;
    auto oneStepAheadSample = magnitude + signalDeltarivative;

//    auto excitationThreshold = EXCITATION_AXIOM * 1000;



    if (excited) {
        // float around
        auto distance = magnitude / 50 * MOVEMENT_AXIOM;
//        auto direction = randomizer->generateProportion() * 2 * M_PI;
        float direction = 0;
        if (randomizer->generateProportion() > 0.5) {
            direction = M_PI;
        }
        auto potentialNewLatticePoint = cartographer->shiftPoint(latticePoint, distance, direction);
        if (cartographer->isValid(potentialNewLatticePoint)) {
            latticePoint = potentialNewLatticePoint;
        }
        if (magnitude < excitationThreshold / (8 * EXHAUSTION_AXIOM)) {
            excited = false;
        }
    } else if (magnitude > excitationThreshold) {
        // the flip
//        LOGGER->info(magnitude);
        excited = true;
        excitationMagnitude = magnitude;
        lumionBookie->recordActivation(magnitude);
        color = chromatica->getColor();
        color = {color.hue, color.saturation, color.lightness};
    }

    if (excited) {
        // make some glimmers
        aspectCommunity->revealeries[macroMode]->reveal(this);
    } else {
        if (centerMode) {
            center();
        }
    }
    previousMagnitude = magnitude;
}

void Lumion::center() {
    latticePoint = {cast(float, constants->percipiaWidth / 2), cast(float, constants->percipiaHeight / 2)};
}

}
