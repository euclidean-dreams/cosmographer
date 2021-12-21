#ifndef COSMOGRAPHER_RANDOMSCATTER_H
#define COSMOGRAPHER_RANDOMSCATTER_H

#include "cosmology/illuminable/Illuminable.h"

namespace cosmographer {

class RandomScatter : public Illuminable {
private:
    int radius;
    float density;

public:
    RandomScatter(Coordinate origin, HSLColor soulColor, int radius, float density);

    void illuminate(Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_RANDOMSCATTER_H
