#ifndef COSMOGRAPHER_DRAGONCURVE_H
#define COSMOGRAPHER_DRAGONCURVE_H

#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"

namespace cosmographer {

class DragonCurve : public Illuminable {
public:
    void illuminate(
            Lattice &lattice
    ) override;
};

}

#endif //COSMOGRAPHER_DRAGONCURVE_H
