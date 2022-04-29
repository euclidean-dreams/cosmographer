#ifndef COSMOGRAPHER_ILLUMINABLE_H
#define COSMOGRAPHER_ILLUMINABLE_H

#include "Default.h"
#include "primitive/Lattice.h"

namespace cosmographer {

// nothing in subclasses should call out - these are multithreaded
class Illuminable : public Element {
protected:
    int baseSize = (CONSTANTS->latticeWidth * CONSTANTS->latticeHeight) / 1000;
public:
    virtual ~Illuminable() = default;

    virtual void illuminate(
            Lattice &lattice
    ) = 0;
};

}

#endif //COSMOGRAPHER_ILLUMINABLE_H
