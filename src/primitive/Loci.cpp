#include "Loci.h"

namespace cosmographer {

Point::Point(

) :
        Point(0, 0, 0) {

}

Point::Point(
        double x
) :
        Point(x, 0, 0) {

}

Point::Point(
        double x,
        double y
) :
        Point(x, y, 0) {

}

Point::Point(
        int x,
        int y
) :
        Point(x, y, 0) {

}

Point::Point(
        double x,
        double y,
        double z
) :
        x{x},
        y{y},
        z{z} {

}

}
