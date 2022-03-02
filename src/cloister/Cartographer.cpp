#include "Cartographer.h"
#include "default.h"

namespace cosmographer {

Point Cartographer::verticalWrap(int index) {
    return {cast(double, index % PARADIGM->latticeWidth),
            std::floor(index / PARADIGM->latticeWidth)};
}

int Cartographer::verticalUnwrap(Point point) {
    return point.y * PARADIGM->latticeWidth + point.x;
}

bool Cartographer::isValid(Point point) {
    if (point.x > 0 && point.x < PARADIGM->latticeWidth) {
        if (point.y > 0 && point.y < PARADIGM->latticeHeight) {
            return true;
        }
    }
    return false;
}

Point Cartographer::shiftPoint(
        Point point,
        float distance,
        float angle
) {
    auto x = point.x + distance * cos(angle);
    auto y = point.y + distance * sin(angle);
    return {x, y, point.z};
}

}
