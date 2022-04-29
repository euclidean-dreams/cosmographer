#ifndef COSMOGRAPHER_LUMION_H
#define COSMOGRAPHER_LUMION_H

#include "cosmology/aspect/mesh/MeshCommunity.h"
#include "primitive/Loci.h"
#include "primitive/Signal.h"
#include "cosmology/aspect/AspectCommunity.h"

namespace cosmographer {

class Lumion : public Fellow<MeshCommunity> {
public:
    AspectCommunity *aspectCommunity;
    int signalIndex;
    Point latticePoint;
    bool excited;
    float magnitude;
    HSLColor color;

    Lumion(
            AspectCommunity *aspectCommunity,
            int signalIndex,
            Point latticePoint
    );

    void react();

    void center();
};

}

#endif //COSMOGRAPHER_LUMION_H
