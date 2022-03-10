#include "Sketcher.h"

namespace cosmographer {

Sketcher::Sketcher(
        Point location,
        float orientation
) :
        location{location},
        orientation{orientation} {

}

void Sketcher::establishAffinity(
        Canvas *canvas
) {
    canvasAffinity = canvas;
}

void Sketcher::advance(
        float distance
) {
    location = CLOISTER->cartographer->shiftPoint(location, distance, orientation);
    canvasAffinity->draw(location);
}

void Sketcher::rotate(
        float newOrientation
) {
    orientation = newOrientation;
}

}
