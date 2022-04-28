#ifndef COSMOGRAPHER_LUMION_H
#define COSMOGRAPHER_LUMION_H

#include "cosmology/aspect/mesh/MeshCommunity.h"
#include "primitive/Loci.h"
#include "primitive/Signal.h"
#include "cosmology/aspect/AspectCommunity.h"

namespace cosmographer {

class LumionExcitation {
public:
    Point point;
    int signalIndex;
    float magnitude;
    float energy;
};

class Lumion : public Fellow<MeshCommunity> {
public:
    AspectCommunity *aspectCommunity;
    int signalIndex;
    Point latticePoint;

    Lumion(
            AspectCommunity *aspectCommunity,
            int signalIndex,
            Point latticePoint
    );

    void excite();
};

}

#endif //COSMOGRAPHER_LUMION_H
