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

struct Point {
    float x;
    float y;
};

void initializeCoordinateHash();

struct CoordinateHash {
    size_t operator()(const Coordinate &locus) const;
};

}

#endif //COSMOGRAPHER_LOCI_H
