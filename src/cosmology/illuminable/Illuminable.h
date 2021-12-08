#ifndef COSMOGRAPHER_ILLUMINABLE_H
#define COSMOGRAPHER_ILLUMINABLE_H

#include <ImpresarioUtils.h>
#include "gizmo/Lattice.h"

namespace cosmographer {

class Illuminable : public impresarioUtils::NonCopyable {
public:
    virtual ~Illuminable() = default;

    virtual void illuminate(Lattice &lattice) = 0;
};

}

#endif //COSMOGRAPHER_ILLUMINABLE_H
