#ifndef COSMOGRAPHER_LOCI_H
#define COSMOGRAPHER_LOCI_H

#include "framework/Minimal.h"

namespace cosmographer {

struct Coordinate {
    int x;
    int y;
};

struct Point {
    double x;
    double y;

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

struct PointHash {
    size_t operator()(const Point &point) const {
        return point.x + point.y;
    }
};

}

#endif //COSMOGRAPHER_LOCI_H
