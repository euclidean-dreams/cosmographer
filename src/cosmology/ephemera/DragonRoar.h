#ifndef COSMOGRAPHER_DRAGONROAR_H
#define COSMOGRAPHER_DRAGONROAR_H

#include "cosmology/ephemera/Ephemera.h"
#include "cosmology/illuminable/lindogram/DragonCurve.h"

namespace cosmographer {

class DragonRoar : public Ephemera {
private:
    std::unique_ptr<DragonCurve> dragonCurve;

public:
    DragonRoar(Coordinate origin, HSLColor soulColor);

    void live(Lattice &lattice) override;

    bool isDead() override;

};

}

#endif //COSMOGRAPHER_DRAGONROAR_H
