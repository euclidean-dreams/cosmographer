#ifndef COSMOGRAPHER_FULLYFADED_H
#define COSMOGRAPHER_FULLYFADED_H

#include "Terminus.h"

namespace cosmographer {

class FullyFaded : public Terminus {
    bool shouldTerminate() override {
        return community->color == PARADIGM->latticeInitialColor;
    }
};

}

#endif //COSMOGRAPHER_FULLYFADED_H
