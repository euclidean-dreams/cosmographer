#ifndef COSMOGRAPHER_BLOOM_H
#define COSMOGRAPHER_BLOOM_H

#include "cosmology/ephemera/Ephemera.h"
#include "cosmology/illuminable/shape/Circle.h"

namespace cosmographer {

class Bloom : public Ephemera {
private:
    Coordinate origin;
    HSLColor innerColor;

public:
    Bloom(Coordinate origin, HSLColor color);

    void live(Lattice &lattice) override;

    bool isDead() override;
};

}

#endif //COSMOGRAPHER_BLOOM_H
