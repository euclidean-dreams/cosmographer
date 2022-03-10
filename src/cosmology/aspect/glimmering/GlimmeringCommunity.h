#ifndef COSMOGRAPHER_GLIMMERINGCOMMUNITY_H
#define COSMOGRAPHER_GLIMMERINGCOMMUNITY_H

#include <condition_variable>
#include "Default.h"

namespace cosmographer {

class GlimmeringCommunity : public Community {
public:
    lst<up<class Glimmer>> glimmers;
    up<class Orchestrator> orchestrator;
    std::mutex illuminatorKickoffMutex;
    std::condition_variable illuminatorKickoff;
    std::mutex illuminatorFinishMutex;
    std::condition_variable illuminatorFinish;
    int finishedIlluminators;
    vec<up<std::thread>> illuminatorThreads;
    vec<up<class Lattice>> illuminatorLattices;
    vec<vec<class Glimmer *>> illuminatorTasking;
};

}

#endif //COSMOGRAPHER_GLIMMERINGCOMMUNITY_H
