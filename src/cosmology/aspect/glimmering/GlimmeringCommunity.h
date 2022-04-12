#ifndef COSMOGRAPHER_GLIMMERINGCOMMUNITY_H
#define COSMOGRAPHER_GLIMMERINGCOMMUNITY_H

#include "Default.h"
#include "oddments/Antechamber.h"

namespace cosmographer {

class GlimmeringCommunity : public Community {
public:
    lst<up<class Glimmer>> glimmers;
    up<class Orchestrator> orchestrator;
    up<Antechamber> kickoffAntechamber;
    up<Antechamber> completionAntechamber;
    vec<up<std::thread>> illuminatorThreads;
    vec<up<class Lattice>> illuminatorLattices;
    vec<vec<class Glimmer *>> illuminatorTasking;
};

}

#endif //COSMOGRAPHER_GLIMMERINGCOMMUNITY_H
