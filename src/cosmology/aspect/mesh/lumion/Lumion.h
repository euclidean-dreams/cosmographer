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
    int firstIndexToWatch;
    int lastIndexToWatch;
    Point latticePoint;
    bool excited;
    float excitationMagnitude;
    float magnitude = 0;
    float previousMagnitude = 0;
    HSLColor color = {0, 0, 0};

    Lumion(
            AspectCommunity *aspectCommunity,
            int initialWatchedIndex,
            int lastIndexToWatch,
            Point latticePoint
    );

    void react();

    void center();
};

}

#endif //COSMOGRAPHER_LUMION_H
