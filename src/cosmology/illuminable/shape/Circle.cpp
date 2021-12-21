#include "Circle.h"

namespace cosmographer {

Circle::Circle(Coordinate origin, HSLColor soulColor, int radius)
        : Illuminable{origin, soulColor},
          radius{radius} {

}

void Circle::illuminate(Lattice &lattice) {
    auto minX = origin.x - radius;
    if (minX < 0) {
        minX = 0;
    }
    auto minY = origin.y - radius;
    if (minY < 0) {
        minY = 0;
    }
    auto maxX = origin.x + radius;
    if (maxX >= PARADIGM.getLatticeWidth()) {
        maxX = PARADIGM.getLatticeWidth() - 1;
    }
    auto maxY = origin.y + radius;
    if (maxY >= PARADIGM.getLatticeHeight()) {
        maxY = PARADIGM.getLatticeHeight() - 1;
    }
    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            if (radius * radius > (x - origin.x) * (x - origin.x) + (y - origin.y) * (y - origin.y)) {
                lattice.setColorIfValid({x, y}, soulColor);
            }
        }
    }
}

}
