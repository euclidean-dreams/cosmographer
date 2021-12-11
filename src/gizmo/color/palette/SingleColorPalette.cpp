#include "SingleColorPalette.h"

namespace cosmographer {

HSLColor SingleColorPalette::getColor(int index) {
    return {Colorology::hueJitter(AXIOMOLOGY->getScaledHue()), 100, 50};
}

}
