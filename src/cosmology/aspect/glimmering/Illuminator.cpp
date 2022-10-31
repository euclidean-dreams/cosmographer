#include "Illuminator.h"

namespace cosmographer {

Illuminator::Illuminator(
        int identifier
) :
        identifier{identifier} {

}

void Illuminator::activate() {
    community->kickoffAntechamber->lounge();
    auto timer = Timer();
    for (auto glimmer: community->illuminatorTasking[identifier]) {
        if (timer.getTime() < 5000) {
            glimmer->live();
            glimmer->illuminate(*community->illuminatorLattices[identifier]);
        }
    }
    community->completionAntechamber->lounge();
}

}
