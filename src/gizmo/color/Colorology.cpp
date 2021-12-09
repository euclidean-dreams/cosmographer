#include "Colorology.h"

namespace cosmographer {

int Colorology::hueJitter(int hue) {
    int randMax = HUE_JITTER * AXIOMOLOGY->getWildcard(7);
    if (randMax > 0) {
        hue += RANDOM.generate(randMax);
    }
    return hue;
}

}
