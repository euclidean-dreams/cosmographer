#ifndef COSMOGRAPHER_FULLYFADED_H
#define COSMOGRAPHER_FULLYFADED_H

#include "Terminus.h"

namespace cosmographer {

class FullyFaded : public Terminus {
public:
    bool shouldTerminate() override {
        return community->color == CONSTANTS->latticeInitialColor;
    }
};

}

#endif //COSMOGRAPHER_FULLYFADED_H
