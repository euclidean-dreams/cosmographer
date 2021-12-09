#include "SingleColorPalette.h"

namespace cosmographer {

HSLColor SingleColorPalette::getColor(int index) {
    return {Colorology::hueJitter(AXIOMOLOGY->getHue()), 100, 50};
}

}
