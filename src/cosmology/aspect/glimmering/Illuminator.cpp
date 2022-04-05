#include "Illuminator.h"

namespace cosmographer {

Illuminator::Illuminator(
        int identifier
) :
        identifier{identifier} {

}

void Illuminator::activate() {
    community->kickoffAntechamber->lounge();
    for (auto glimmer: community->illuminatorTasking[identifier]) {
        glimmer->illuminate(*community->illuminatorLattices[identifier]);
    }
    community->completionAntechamber->lounge();
}

}
