#ifndef COSMOGRAPHER_RANDOMWALK_H
#define COSMOGRAPHER_RANDOMWALK_H

#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"
#include "LindogramCommunity.h"

namespace cosmographer {

class RandomWalk : public Illuminable, public Liaison<LindogramCommunity> {
public:
    float spin;

    RandomWalk(
            Paradigm *paradigm,
            float orientation,
            float spin
    );

    void illuminate(Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_RANDOMWALK_H
