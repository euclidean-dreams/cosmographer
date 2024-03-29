#ifndef COSMOGRAPHER_ILLUMINABLE_H
#define COSMOGRAPHER_ILLUMINABLE_H

#include "Default.h"
#include "primitive/Lattice.h"
#include "cosmology/revealeryaspect/mesh/lumion/Lumion.h"

namespace cosmographer {

// nothing in subclasses should call out - these are multithreaded
class Illuminable : public Element {
public:
    ~Illuminable() override = default;

    virtual void illuminate(
            Lattice &lattice
    ) = 0;
};

}

#endif //COSMOGRAPHER_ILLUMINABLE_H
