#ifndef COSMOGRAPHER_LIVELY_H
#define COSMOGRAPHER_LIVELY_H

#include "Default.h"

namespace cosmographer {

class Lively : public Element {
public:
    virtual ~Lively() = default;

    virtual void live() = 0;
};

}

#endif //COSMOGRAPHER_LIVELY_H
