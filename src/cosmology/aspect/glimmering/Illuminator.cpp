#include "Illuminator.h"

namespace cosmographer {

Illuminator::Illuminator(
        int identifier
) :
        identifier{identifier} {

}

void Illuminator::activate() {
    {
        std::unique_lock<std::mutex> lock(community->illuminatorKickoffMutex);
        community->illuminatorKickoff.wait(lock);
    }
    for (auto glimmer: community->illuminatorTasking[identifier]) {
        glimmer->illuminate(*community->illuminatorLattices[identifier]);
    }
    {
        std::unique_lock<std::mutex> lock{community->illuminatorFinishMutex};
        community->finishedIlluminators++;
        community->illuminatorFinish.notify_all();
    }
}

}
