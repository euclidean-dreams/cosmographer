#include "LumionBookie.h"

namespace cosmographer {

LumionBookie::LumionBookie(

) :
        activationCount{0},
        maxActivation{0} {
}

void LumionBookie::recordActivation(float activation) {
    activationCount++;
    if (activation > maxActivation) {
        maxActivation = activation;
    }
}

void LumionBookie::clear() {
    activationCount = 0;
    maxActivation = 0;
}

}
