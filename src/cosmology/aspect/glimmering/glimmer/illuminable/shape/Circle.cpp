#include "Circle.h"

namespace cosmographer {

Circle::Circle(
        GlimmerSoul *glimmerSoul
) :
        glimmerSoul{glimmerSoul} {
}

void Circle::illuminate(
        Lattice &lattice
) {
    auto radius = glimmerSoul->size;
    auto locus = glimmerSoul->locus;
    auto minX = locus.x - radius;
    if (minX < 0) {
        minX = 0;
    }
    auto minY = locus.y - radius;
    if (minY < 0) {
        minY = 0;
    }
    auto maxX = locus.x + radius;
    if (maxX >= CONSTANTS->latticeWidth) {
        maxX = CONSTANTS->latticeWidth - 1;
    }
    auto maxY = locus.y + radius;
    if (maxY >= CONSTANTS->latticeHeight) {
        maxY = CONSTANTS->latticeHeight - 1;
    }
    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            if (radius * radius >
                (x - locus.x) * (x - locus.x) +
                (y - locus.y) * (y - locus.y)) {
                if (lattice.isValid(x, y)) {
                    lattice.setColor(x, y, glimmerSoul->color);
                }
            }
        }
    }
}

}
