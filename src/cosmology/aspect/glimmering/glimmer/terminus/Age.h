#ifndef COSMOGRAPHER_AGE_H
#define COSMOGRAPHER_AGE_H

#include "Terminus.h"

namespace cosmographer {

class Age : public Terminus {
public:
    int lifespan;

    Age(
            int lifespan
    ) :
            lifespan{lifespan} {}

    bool shouldTerminate() override {
        return community->age >= lifespan;
    }
};

}

#endif //COSMOGRAPHER_AGE_H
