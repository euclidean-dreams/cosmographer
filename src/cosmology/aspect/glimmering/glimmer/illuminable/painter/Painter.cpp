#include "Painter.h"

namespace cosmographer {

Painter::Painter(
        PainterCommunity *painterCommunity
) :
        painterCommunity{painterCommunity},
        location{0, 0},
        orientation{0} {

}

void Painter::advance(
        float distance,
        HSLColor color
) {
    location = cartographer->shiftPoint(location, distance, orientation);
    painterCommunity->canvas->paint({cast(int, location.x), cast(int, location.y)}, color);
}

void Painter::rotate(
        float newOrientation
) {
    orientation += newOrientation;
}

}
