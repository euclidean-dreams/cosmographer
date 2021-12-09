#include "RandomPalette.h"

namespace cosmographer {

HSLColor RandomPalette::getColor(int index) {
    return {RANDOM.generate(HSL_HUE_MAX), 100, 50};
}

}
