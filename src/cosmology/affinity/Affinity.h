#ifndef COSMOGRAPHER_AFFINITY_H
#define COSMOGRAPHER_AFFINITY_H

#include <ImpresarioUtils.h>
#include "gizmo/Lattice.h"

namespace cosmographer {

class Affinity: public impresarioUtils::NonCopyable {
public:
    virtual std::unique_ptr<Lattice> manifest(int tick) = 0;

    virtual void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) = 0;

    virtual void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) = 0;
};

}

#endif //COSMOGRAPHER_AFFINITY_H
