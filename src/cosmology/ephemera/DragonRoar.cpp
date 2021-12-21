#include "DragonRoar.h"

namespace cosmographer {

DragonRoar::DragonRoar(Coordinate origin, HSLColor soulColor)
        : Ephemera(origin, soulColor) {
    double orientation = RANDOM.generateProportion() * 2 * M_PI;
    dragonCurve = std::make_unique<DragonCurve>(origin, soulColor, orientation, 10, AXIOMOLOGY.getWildcard(0));
}

void DragonRoar::live(Lattice &lattice) {
    auto axiomology = AXIOMOLOGY;
    for (int index = 0; index < 100 * axiomology.getWildcard(2); index++) {
        dragonCurve->tick();
    }
    dragonCurve->illuminate(lattice);
    soulColor = soulColor.darken(age / (axiomology.getWildcard(1) * 25));
    dragonCurve->changeSoulColor(soulColor);
}

bool DragonRoar::isDead() {
    return soulColor.getLightness() == 0;
}
}
