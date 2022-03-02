#include "Circle.h"

namespace cosmographer {

Circle::Circle(
        int radius
) :
        radius{radius} {
}

void Circle::illuminate(
        Lattice &lattice
) {
    auto locus = community->locus;
    auto minX = locus.x - radius;
    if (minX < 0) {
        minX = 0;
    }
    auto minY = locus.y - radius;
    if (minY < 0) {
        minY = 0;
    }
    auto maxX = locus.x + radius;
    if (maxX >= PARADIGM->latticeWidth) {
        maxX = PARADIGM->latticeWidth - 1;
    }
    auto maxY = locus.y + radius;
    if (maxY >= PARADIGM->latticeHeight) {
        maxY = PARADIGM->latticeHeight - 1;
    }
    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            if (radius * radius >
                (x - locus.x) * (x - locus.x) +
                (y - locus.y) * (y - locus.y)) {
                if (lattice.isValid(x, y)) {
                    lattice.setColor(x, y, community->color);
                }
            }
        }
    }
}
}
