#ifndef COSMOGRAPHER_BURST_H
#define COSMOGRAPHER_BURST_H

#include "cosmology/ephemera/Ephemera.h"
#include "cosmology/illuminable/RandomScatter.h"

namespace cosmographer {

class Burst : public Ephemera {
private:
    float scale;

public:
    Burst(Coordinate origin, HSLColor soulColor, float scale);

    void live(Lattice &lattice) override;

    bool isDead() override;
};

}

#endif //COSMOGRAPHER_BURST_H
