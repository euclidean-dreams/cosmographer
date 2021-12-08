#ifndef COSMOGRAPHER_CIRCLE_H
#define COSMOGRAPHER_CIRCLE_H

#include "cosmology/illuminable/Illuminable.h"

namespace cosmographer {

class Circle : public Illuminable {
private:
    Coordinate origin;
    HSLColor color;
    int radius;

public:
    Circle(Coordinate origin, HSLColor color, int radius);

    void illuminate(Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_CIRCLE_H
