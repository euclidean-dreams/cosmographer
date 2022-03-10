#include "Grow.h"

namespace cosmographer {

void Grow::live() {
    int rate = 10 - EPHEMERA_AXIOM_0 * 10;
    if (rate == 0) {
        rate = 1;
    }
    if (community->age % rate== 0) {
        community->size++;
    }
}

}
