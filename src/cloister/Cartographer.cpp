#include "Cartographer.h"
#include "Default.h"

namespace cosmographer {

Point Cartographer::verticalWrap(int index) {
    return {cast(float, index % constants->percipiaWidth),
            cast(float, std::floor(index / constants->percipiaWidth))};
}

int Cartographer::verticalUnwrap(Point point) {
    return point.y * constants->percipiaWidth + point.x;
}

bool Cartographer::isValid(Point point) {
    if (point.x > 0 && point.x < constants->percipiaWidth) {
        if (point.y > 0 && point.y < constants->percipiaHeight) {
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
    float x = point.x + distance * cos(direction);
    float y = point.y + distance * sin(direction);
    return {x, y};
}

}
