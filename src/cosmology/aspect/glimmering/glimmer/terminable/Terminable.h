#ifndef COSMOGRAPHER_TERMINABLE_H
#define COSMOGRAPHER_TERMINABLE_H

#include "Default.h"

namespace cosmographer {

class Terminable : public Constituent {
public:
    virtual ~Terminable() = default;

    virtual bool shouldTerminate() = 0;
};

}

#endif //COSMOGRAPHER_TERMINABLE_H
