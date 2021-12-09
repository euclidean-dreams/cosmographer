#ifndef COSMOGRAPHER_CIRCLE_H
#define COSMOGRAPHER_CIRCLE_H

#include "cosmology/illuminable/Illuminable.h"

namespace cosmographer {

class Circle : public Illuminable {
private:
    int radius;

public:
    Circle(Coordinate origin, HSLColor soulColor, int radius);

    void illuminate(Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_CIRCLE_H
