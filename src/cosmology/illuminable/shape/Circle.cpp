#include "Circle.h"

namespace cosmographer {

Circle::Circle(Coordinate origin, HSLColor soulColor, int radius)
        : Illuminable{origin, soulColor},
          radius{radius} {

}

void Circle::illuminate(Lattice &lattice) {
    for (int y = origin.y - radius; y < origin.y + radius; y++) {
        for (int x = origin.x - radius; x < origin.x + radius; x++) {
            if (lattice.isValid({x, y})) {
                if (std::pow(radius, 2) > std::pow(x - origin.x, 2) + std::pow(y - origin.y, 2)) {
                    lattice.setColor({x, y}, soulColor);
                }
            }
        }
    }
}

}
