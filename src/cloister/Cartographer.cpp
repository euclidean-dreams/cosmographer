#include "Cartographer.h"
#include "Default.h"

namespace cosmographer {

Point Cartographer::verticalWrap(int index) {
    return {cast(double, index % CONSTANTS->latticeWidth),
            std::floor(index / CONSTANTS->latticeWidth)};
}

int Cartographer::verticalUnwrap(Point point) {
    return point.y * CONSTANTS->latticeWidth + point.x;
}

bool Cartographer::isValid(Point point) {
    if (point.x > 0 && point.x < CONSTANTS->latticeWidth) {
        if (point.y > 0 && point.y < CONSTANTS->latticeHeight) {
            return true;
        }
    }
    return false;
}

Point Cartographer::shiftPoint(
        Point point,
        float distance,
        float direction
) {
    auto x = point.x + distance * cos(direction);
    auto y = point.y + distance * sin(direction);
    return {x, y};
}

}
