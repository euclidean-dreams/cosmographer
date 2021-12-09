#include "Colorium.h"

namespace cosmographer {

Colorium::Colorium(std::unique_ptr<Palette> palette)
        : palette{move(palette)} {

}

HSLColor Colorium::getColor() {
    return getColor(0);
}

HSLColor Colorium::getColor(int index) {
    return palette->getColor(index);
}

}
