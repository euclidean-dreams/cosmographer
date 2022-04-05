#include "Painter.h"

namespace cosmographer {

Painter::Painter(
) :
        location{0, 0},
        orientation{0} {

}

void Painter::advance(
        float distance,
        HSLColor color
) {
    location = CLOISTER->cartographer->shiftPoint(location, distance, orientation);
    community->canvas->paint(location, color);
}

void Painter::rotate(
        float newOrientation
) {
    orientation += newOrientation;
}

}
