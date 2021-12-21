#include "RandomScatter.h"

namespace cosmographer {

RandomScatter::RandomScatter(Coordinate origin, HSLColor soulColor, int radius, float density)
        : Illuminable(origin, soulColor),
          radius{radius},
          density{density} {

}

void RandomScatter::illuminate(Lattice &lattice) {
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
            if (RANDOM.generateProportion() < density) {
                lattice.setColorIfValid({x, y}, soulColor);
            }
        }
    }
}

}
