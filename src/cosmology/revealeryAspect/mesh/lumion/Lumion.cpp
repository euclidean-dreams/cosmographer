#include "Lumion.h"
#include "oddments/Tidbit.h"
#include "cosmology/revealeryaspect/revealery/Revealery.h"

namespace cosmographer {

Lumion::Lumion(
        RevealeryAspectCommunity *aspectCommunity,
        int lumionIndex,
        int firstIndexToWatch,
        int lastIndexToWatch
) :
        aspectCommunity{aspectCommunity},
        lumionIndex{lumionIndex},
        firstIndexToWatch{firstIndexToWatch},
        lastIndexToWatch{lastIndexToWatch},
        latticePoint{0, 0} {
    place();
}

void Lumion::react() {
    place();
    color = chromatica->getColor();
    color.hue += lumionIndex * COLOR_ACCENT_AXIOM;

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
    auto derivative = magnitude - previousMagnitude;

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
    auto cutoffThreshold = flippedExcitationAxiom * stateChangeThresholdMax;

    if (magnitude > cutoffThreshold) {
        excited = true;
        place();
        aspectCommunity->revealeries[0]->reveal(this);
    } else {
        excited = false;
    }

    previousMagnitude = magnitude;
    previousDerivative = derivative;
}

void Lumion::center() {
    latticePoint = {cast(float, constants->percipiaWidth / 2), cast(float, constants->percipiaHeight / 2)};
}

void Lumion::place() {
//        auto distance = magnitude / 100 * PLACEMENT_AXIOM;
//        float direction = 0;
//        if (profile == LANTERN_PROFILE) {
//            if (randomizer->generateProportion() > 0.5) {
//                direction = M_PI;
//            }
//        } else {
//            direction = randomizer->generateProportion() * 2 * M_PI;
//        }
//
//        auto potentialNewLatticePoint = cartographer->shiftPoint(latticePoint, distance, direction);
//        if (cartographer->isValid(potentialNewLatticePoint)) {
//            latticePoint = potentialNewLatticePoint;
//        }
    std::complex<double> radius(0.133, 0);
    std::complex<double> poleShifter(pole->pole, 0);
    std::complex<double> spacing(PLACEMENT_AXIOM / 100, 0);
    std::complex<double> t(lumionIndex, 0);
    const std::complex<double> i(0, 1);
    auto complexPoint = radius * t * exp(-2 * M_PI * i * pow(t, 2) * spacing * poleShifter);
    latticePoint = Point{
            cast(float, complexPoint.real()) + cast(float, constants->percipiaWidth) / 2,
            cast(float, complexPoint.imag()) + cast(float, constants->percipiaHeight) / 2,
    };
}

}
