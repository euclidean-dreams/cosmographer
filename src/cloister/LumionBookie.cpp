#include "LumionBookie.h"

namespace cosmographer {

LumionBookie::LumionBookie(

) :
        activationCount{0},
        maxExcitation{0} {
}

void LumionBookie::recordExcitation(float magnitude) {
    activationCount++;
    if (magnitude > maxExcitation) {
        maxExcitation = magnitude;
    }
}

void LumionBookie::clear() {
    activationCount = 0;
    maxExcitation = 0;
}

}
