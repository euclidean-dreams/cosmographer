#include "DragonCurve.h"
#include "Sketcher.h"
#include "DragonCurveSystem.h"

namespace cosmographer {

void DragonCurve::live() {
    auto symbol = dragonCurveSystem[community->age];
    if (symbol == DragonCurveSymbols::advance) {
        community->sketcher->advance(1);
    } else if (symbol == DragonCurveSymbols::rotateLeft) {
        community->sketcher->rotate(M_PI / 2);
    } else if (symbol == DragonCurveSymbols::rotateRight) {
        community->sketcher->rotate(-M_PI / 2);
    }
}

}
