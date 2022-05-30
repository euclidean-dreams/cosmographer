#include "RandomPalette.h"

namespace cosmographer {

HSLColor RandomPalette::getColor() {
    return jitter({randomizer->generate(HSL_HUE_MAX), randomizer->generate(50) + 50, randomizer->generate(60) + 20});
}
}
