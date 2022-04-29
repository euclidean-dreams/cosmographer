#include "RandomPalette.h"

namespace cosmographer {

HSLColor RandomPalette::getColor() {
    return jitter({RANDOM.generate(HSL_HUE_MAX), RANDOM.generate(50) + 50, RANDOM.generate(60) + 20});
}
}
