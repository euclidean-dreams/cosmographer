#include "Rectangle.h"

namespace cosmographer {

Rectangle::Rectangle(
        GlimmerSoul *glimmerSoul,
        int heightRatio
) :
        glimmerSoul{glimmerSoul},
        heightRatio{heightRatio} {

}

void Rectangle::illuminate(
        Lattice &lattice
) {
    auto width = glimmerSoul->size * constants->baseGlimmerSize * SIZE_AXIOM;
    auto height = width * heightRatio;

    auto xLocus = glimmerSoul->locus.x;
    auto yLocus = glimmerSoul->locus.y;
    auto yMin = yLocus - height / 2;
    auto yMax = yLocus + height / 2;
    auto xMin = xLocus - width / 2;
    auto xMax = xLocus + width / 2;
    for (int y = yMin; y <= yMax; y++) {
        for (int x = xMin; x <= xMax; x++) {
            if (lattice.isValid(x, y)) {
                lattice.setColor(x, y, glimmerSoul->color);
            }
        }
    }
}

}
