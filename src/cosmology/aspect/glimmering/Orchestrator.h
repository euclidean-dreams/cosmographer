#ifndef COSMOGRAPHER_ORCHESTRATOR_H
#define COSMOGRAPHER_ORCHESTRATOR_H

#include "GlimmeringCommunity.h"

namespace cosmographer {

class Orchestrator : public Fellow<GlimmeringCommunity> {
public:
    void orchestrate(
            Lattice &resultLattice
    );
};

}

#endif //COSMOGRAPHER_ORCHESTRATOR_H
