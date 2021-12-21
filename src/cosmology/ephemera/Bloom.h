#ifndef COSMOGRAPHER_BLOOM_H
#define COSMOGRAPHER_BLOOM_H

#include "cosmology/ephemera/Ephemera.h"
#include "cosmology/illuminable/shape/Circle.h"

namespace cosmographer {

class Bloom : public Ephemera {
private:
    float scale;

public:
    Bloom(Coordinate origin, HSLColor soulColor, float scale);

    void live(Lattice &lattice) override;

    bool isDead() override;
};

}

#endif //COSMOGRAPHER_BLOOM_H
