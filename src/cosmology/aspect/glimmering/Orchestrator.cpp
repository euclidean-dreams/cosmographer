#include "Orchestrator.h"
#include "glimmer/Glimmer.h"

namespace cosmographer {

void Orchestrator::orchestrate(
        Lattice &resultLattice
) {
    auto illuminatorCount = community->illuminatorThreads.size();

    // trim
    while (community->glimmers.size() > CONSTANTS->maxGlimmers) {
        community->glimmers.pop_front();
    }

    // lifespan
    auto iterator = community->glimmers.begin();
    while (iterator != community->glimmers.end()) {
        (*iterator)->live();
        if ((*iterator)->shouldTerminate()) {
            iterator = community->glimmers.erase(iterator);
        } else {
            iterator++;
        }
    }

    // lattices
    for (int count = 0; count < illuminatorCount; count++) {
        community->illuminatorLattices[count] = mkup<Lattice>(
                CONSTANTS->latticeWidth,
                CONSTANTS->latticeHeight,
                CONSTANTS->latticeInitialColor
        );
    }

    // split glimmers
    for (auto &taskingVector: community->illuminatorTasking) {
        taskingVector.clear();
    }
    auto tasksPerIlluminator = ceil(community->glimmers.size() / illuminatorCount);
    auto glimmerCount = 0;
    for (auto &glimmer: community->glimmers) {
        auto taskingIndex = glimmerCount / tasksPerIlluminator;
        if (taskingIndex >= illuminatorCount) {
            taskingIndex = illuminatorCount - 1;
        }
        community->illuminatorTasking[taskingIndex].push_back(glimmer.get());
        glimmerCount++;
    }

    // wait for illuminators
    community->finishedIlluminators = 0;
    {
        std::unique_lock<std::mutex> lock{community->illuminatorKickoffMutex};
        community->illuminatorKickoff.notify_all();
    }
    {
        std::unique_lock<std::mutex> lock{community->illuminatorFinishMutex};
        while (community->finishedIlluminators < illuminatorCount) {
            community->illuminatorFinish.wait(lock);
        }
    }

    // illuminate
    for (auto &illuminatorLattice: community->illuminatorLattices) {
        resultLattice.meld(*illuminatorLattice);
    }
}

}
