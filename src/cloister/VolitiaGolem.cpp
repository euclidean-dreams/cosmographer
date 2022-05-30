#include "VolitiaGolem.h"
#include "Default.h"
#include "oddments/Tidbit.h"

namespace cosmographer {

VolitiaGolem::VolitiaGolem(

) :
        averageNonZeroLumionActivationCount{constants->signalAverageSize} {

}

void VolitiaGolem::refresh() {
//    if (community->lumionBookie->activationCount > 0) {
//        averageNonZeroLumionActivationCount.addSample(community->lumionBookie->activationCount);
//    }

//    for (int index = 0; index < axioms.size(); index++) {
//        if (index == 6) {
//            auto delta = community->lumionBookie->activationCount / averageNonZeroLumionActivationCount.value - 1;
//            axioms[index] = Tidbit::bind(axioms[index] + 0.1 * delta, 0.1f, 0.9f);
//        } else if (index != 1 && index != 2) {
//            auto deltaMax = 0.01 * community->lumionBookie->activationCount / 50;
//            auto delta = community->randomizer->generateProportion() * deltaMax - deltaMax / 2;
//            axioms[index] = Tidbit::bind(axioms[index] + delta, 0.1f, 0.9f);
//        }
//    }
//    if (community->lumionBookie->activationCount > averageNonZeroLumionActivationCount.value * 5) {
//        microMode = randomizer->generate(5);
//    }
//    if (community->lumionBookie->activationCount > averageNonZeroLumionActivationCount.value * 10) {
//        macroMode = randomizer->generate(5);
//    }
}

}
