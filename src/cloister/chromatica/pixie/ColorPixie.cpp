#include "ColorPixie.h"

namespace cosmographer {

HSLColor ColorPixie::hueJitter(HSLColor color) {
    color.hue += RANDOM.generate(MAX_HUE_JITTER * HUE_JITTER_AXIOM);
    return color;
}

}
