#ifndef COSMOGRAPHER_ASPECT_H
#define COSMOGRAPHER_ASPECT_H

#include <ImpresarioUtils.h>
#include "cosmology/Lattice.h"

namespace cosmographer {

class Aspect : public impresarioUtils::NonCopyable {
public:
    virtual ~Aspect() = default;

    virtual std::unique_ptr<Lattice> manifest(int tick) = 0;

    virtual void alter(const impresarioUtils::Packet &packet) = 0;
};

}

#endif //COSMOGRAPHER_ASPECT_H
