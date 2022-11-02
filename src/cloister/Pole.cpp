#include "Pole.h"
#include "Signalarium.h"
#include "LumionBookie.h"
#include "Constants.h"
#include "oddments/Tidbit.h"
#include "framework/Paradigm.h"
#include "framework/Bindings.h"

namespace cosmographer {

Pole::Pole(

) :
        pole{0},
        deltaDirection{false} {

}

void Pole::refresh() {
    // sensible spins
    auto delta = 0.001 * CHAOS_AXIOM;

    // wacky nonsense
//    auto delta = 1 * CHAOS_AXIOM;
    if (deltaDirection) {
        pole = Tidbit::collapse(pole + delta, 2 * M_PI);
    } else {
        pole = Tidbit::collapse(pole - delta, 2 * M_PI);
    }
}

}
