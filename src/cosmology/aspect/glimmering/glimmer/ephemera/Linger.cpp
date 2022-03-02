#include "Linger.h"

namespace cosmographer {

Linger::Linger(
        bool lighten
) :
        lighten{lighten} {
}

void Linger::live() {
    auto lifespan = EPHEMERA_AXIOM_0;
    if (lifespan < 0.01) {
        lifespan = 0.01;
    }
    if (lighten) {
        community->color.lightness += community->age / (lifespan * 50);
        if (community->color.lightness > 100) {
            community->color.lightness = 100;
        }
    } else {
        community->color.lightness -= community->age / (lifespan * 50);
        if (community->color.lightness < 0) {
            community->color.lightness = 0;
        }
    }
    community->age++;
}

bool Linger::isAlive() {
    if (community->color.lightness == 100 || community->color.lightness == 0) {
        return false;
    } else return true;
}

}
