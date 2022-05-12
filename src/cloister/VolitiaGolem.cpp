#include "VolitiaGolem.h"
#include "Default.h"
#include "oddments/Tidbit.h"

namespace cosmographer {

void VolitiaGolem::refresh() {
    for (int index = 0; index < paradigm->axioms.size(); index++) {
        if (index != 1 && index != 2 && index != 6 && index != 7) {
            auto deltaMax = community->lumionBookie->activationCount / 50;
            auto delta = community->randomizer->generateProportion() * deltaMax - deltaMax / 2;
            paradigm->axioms[index] = Tidbit::bind(paradigm->axioms[index] + delta, 0.1f, 0.9f);
        }
    }
    if (community->lumionBookie->activationCount > 10) {
        paradigm->macroMode = CLOISTER->randomizer->generate(5);
        paradigm->microMode = CLOISTER->randomizer->generate(5);
    }
}

}
