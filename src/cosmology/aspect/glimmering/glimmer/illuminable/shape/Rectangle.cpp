#include "Rectangle.h"

namespace cosmographer {

Rectangle::Rectangle(
        GlimmerCommunity *glimmerCommunity,
        int heightRatio
) :
        glimmerCommunity{glimmerCommunity},
        heightRatio{heightRatio} {

}

void Rectangle::illuminate(
        Lattice &lattice
) {
    auto xLocus = glimmerCommunity->locus.x;
    auto yLocus = glimmerCommunity->locus.y;
    auto width = glimmerCommunity->size;
    auto height = glimmerCommunity->size * heightRatio;
    auto yMin = yLocus - height / 2;
    auto yMax = yLocus + height / 2;
    auto xMin = xLocus - width / 2;
    auto xMax = xLocus + width / 2;
    for (int y = yMin; y <= yMax; y++) {
        for (int x = xMin; x <= xMax; x++) {
            if (lattice.isValid(x, y)) {
                lattice.setColor(x, y, glimmerCommunity->color);
            }
        }
    }
}

}
