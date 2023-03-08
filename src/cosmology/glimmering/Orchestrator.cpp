#include "Orchestrator.h"
#include "cosmology/glimmering/glimmer/Glimmer.h"

namespace cosmographer {

void Orchestrator::orchestrate(
        Lattice &resultLattice
) {
    auto illuminatorCount = community->illuminatorThreads.size();

    // trim
    while (community->glimmers.size() > constants->maxGlimmers * COSMOLOGY_SIZE_AXIOM) {
        community->glimmers.pop_front();
    }

    // lifespan
    auto iterator = community->glimmers.begin();
    while (iterator != community->glimmers.end()) {
        if ((*iterator)->shouldTerminate()) {
            iterator = community->glimmers.erase(iterator);
        } else {
            iterator++;
        }
    }

    // lattices
    for (int count = 0; count < illuminatorCount; count++) {
        community->illuminatorLattices[count] = mkup<Lattice>(
                constants->percipiaWidth,
                constants->percipiaHeight,
                constants->latticeInitialColor
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
    community->kickoffAntechamber->lounge();
    community->kickoffAntechamber->clean();
    community->completionAntechamber->lounge();
    community->completionAntechamber->clean();

    // illuminate
    for (auto &illuminatorLattice: community->illuminatorLattices) {
        resultLattice.meld(*illuminatorLattice);
    }
}

}
