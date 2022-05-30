#include "Pole.h"
#include "Signalarium.h"
#include "LumionBookie.h"
#include "Constants.h"
#include "oddments/Tidbit.h"
#include "framework/Paradigm.h"

namespace cosmographer {

Pole::Pole(

) :
        pole{0},
        deltaDirection{false} {

}

void Pole::refresh() {
    auto delta = lumionBookie->activationCount * 0.001;
    if (deltaDirection) {
        pole = Tidbit::collapse(pole + delta, 2 * M_PI);
    } else {
        pole = Tidbit::collapse(pole - delta, 2 * M_PI);
    }
}

}
