#ifndef COSMOGRAPHER_LOCI_H
#define COSMOGRAPHER_LOCI_H

#include "framework/Minimal.h"

namespace cosmographer {

struct Coordinate {
    int x;
    int y;

    bool operator==(const Coordinate &other) const {
        return x == other.x && y == other.y;
    }
};

struct CoordinateHash {
    size_t operator()(const Coordinate &locus) const {
        return locus.x + locus.y;
    }
};

struct Point {
    double x;
    double y;
};

}

#endif //COSMOGRAPHER_LOCI_H
