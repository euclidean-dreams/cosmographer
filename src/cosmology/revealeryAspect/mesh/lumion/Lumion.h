#ifndef COSMOGRAPHER_LUMION_H
#define COSMOGRAPHER_LUMION_H

#include "cosmology/revealeryAspect/mesh/MeshCommunity.h"
#include "primitive/Loci.h"
#include "primitive/Signal.h"
#include "cosmology/revealeryAspect/RevealeryAspectCommunity.h"
#include <complex>

namespace cosmographer {

class Lumion : public Fellow<MeshCommunity> {
public:
    RevealeryAspectCommunity *aspectCommunity;
    int lumionIndex;
    int firstIndexToWatch;
    int lastIndexToWatch;
    Point latticePoint;
    bool excited;
    float excitationMagnitude;
    float magnitude = 0;
    float previousMagnitude = 0;
    float previousDerivative = 0;
    HSLColor color = {0, 0, 0};

    Lumion(
            RevealeryAspectCommunity *aspectCommunity,
            int lumionIndex,
            int initialWatchedIndex,
            int lastIndexToWatch
    );

    void react();

    void center();

    void place();
};

}

#endif //COSMOGRAPHER_LUMION_H
