#ifndef COSMOGRAPHER_LOCI_H
#define COSMOGRAPHER_LOCI_H

#include "framework/Minimal.h"

namespace cosmographer {

class Point {
public:
    double x;
    double y;
    double z;

    Point();

    Point(
            double x
    );

    Point(
            double x,
            double y
    );

    Point(
            int x,
            int y
    );

    Point(
            double x,
            double y,
            double z
    );
};

}

#endif //COSMOGRAPHER_LOCI_H
