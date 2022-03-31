#ifndef COSMOGRAPHER_LUMION_H
#define COSMOGRAPHER_LUMION_H

#include "cosmology/aspect/mesh/MeshCommunity.h"
#include "primitive/Loci.h"
#include "primitive/Signal.h"

namespace cosmographer {

class LumionExcitation {
public:
    Point point;
    float magnitude;
    float energy;
};

class Lumion : public Fellow<MeshCommunity> {
public:
    int signalIndex;
    Point latticePoint;

    Lumion(
            int signalIndex,
            Point latticePoint
    );

    LumionExcitation excite(
            Signal &signal
    );
};

}

#endif //COSMOGRAPHER_LUMION_H
