#ifndef COSMOGRAPHER_PARABOLOID_H
#define COSMOGRAPHER_PARABOLOID_H

#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"

namespace cosmographer {

class Paraboloid : public Illuminable {
public:
    int power;

    Paraboloid(
            int power
    );

    void illuminate(
            Lattice &lattice
    ) override;
};

}

#endif //COSMOGRAPHER_PARABOLOID_H
