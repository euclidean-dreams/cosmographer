#include "Rectangle.h"

namespace cosmographer {

Rectangle::Rectangle(
        int heightRatio
) :
        heightRatio{heightRatio} {

}

void Rectangle::illuminate(
        Lattice &lattice
) {
    auto xLocus = community->locus.x;
    auto yLocus = community->locus.y;
    auto width = community->size;
    auto height = community->size * heightRatio;
    auto yMin = yLocus - height / 2;
    auto yMax = yLocus + height / 2;
    auto xMin = xLocus - width / 2;
    auto xMax = xLocus + width / 2;
    for (int y = yMin; y <= yMax; y++) {
        for (int x = xMin; x <= xMax; x++) {
            if (lattice.isValid(x, y)) {
                lattice.setColor(x, y, community->color);
            }
        }
    }
}

}
