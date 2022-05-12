#include "RandomPalette.h"

namespace cosmographer {

HSLColor RandomPalette::getColor() {
    return jitter({CLOISTER->randomizer->generate(HSL_HUE_MAX), CLOISTER->randomizer->generate(50) + 50, CLOISTER->randomizer->generate(60) + 20});
}
}
