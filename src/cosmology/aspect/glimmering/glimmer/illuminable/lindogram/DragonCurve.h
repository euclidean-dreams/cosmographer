#ifndef COSMOGRAPHER_DRAGONCURVE_H
#define COSMOGRAPHER_DRAGONCURVE_H

#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"
#include "LindogramCommunity.h"

namespace cosmographer {

class DragonCurve : public Illuminable, public Liaison<LindogramCommunity> {
public:
    int lastRuneIndex;

    DragonCurve(
            Paradigm *paradigm,
            float orientation
    );

    void illuminate(Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_DRAGONCURVE_H
