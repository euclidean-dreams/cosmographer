#include "Pole.h"
#include "Signalarium.h"
#include "LumionBookie.h"
#include "Constants.h"
#include "oddments/Tidbit.h"

namespace cosmographer {

Pole::Pole(

) :
        pole{0},
        deltaDirection{false} {

}

void Pole::refresh() {
    auto delta = community->lumionBookie->activationCount * 0.001;
    if (deltaDirection) {
        pole = Tidbit::collapse(pole + delta, 2 * M_PI);
    } else {
        pole = Tidbit::collapse(pole - delta, 2 * M_PI);
    };
}

}
