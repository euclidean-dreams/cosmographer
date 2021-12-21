#ifndef COSMOGRAPHER_POINT_H
#define COSMOGRAPHER_POINT_H

namespace cosmographer {

class Point {
public:
    double x;
    double y;
    double z;

    Point();

    Point(double x);

    Point(double x, double y);

    Point(double x, double y, double z);

};

}

#endif //COSMOGRAPHER_POINT_H
