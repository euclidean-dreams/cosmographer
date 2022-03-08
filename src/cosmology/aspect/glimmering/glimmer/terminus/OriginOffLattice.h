#ifndef COSMOGRAPHER_ORIGINOFFLATTICE_H
#define COSMOGRAPHER_ORIGINOFFLATTICE_H

#include "Terminus.h"

namespace cosmographer {

class OriginOffLattice : public Terminus {
    bool shouldTerminate() override {
        return !CLOISTER->cartographer->isValid(community->locus);
    }
};

}

#endif //COSMOGRAPHER_ORIGINOFFLATTICE_H
