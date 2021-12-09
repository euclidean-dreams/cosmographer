#ifndef COSMOGRAPHER_ASPECT_H
#define COSMOGRAPHER_ASPECT_H

#include <ImpresarioUtils.h>
#include "cosmology/ephemera/EphemeraEcosystem.h"
#include "gizmo/Lattice.h"
#include "gizmo/CoordinateTransformer.h"
#include "gizmo/color/colorium/Colorium.h"
#include "gizmo/paradigm/Paradigm.h"

namespace cosmographer {

class Aspect : public impresarioUtils::NonCopyable {
public:
    virtual ~Aspect() = default;

    virtual std::unique_ptr<Lattice> manifest(int tick) = 0;

    virtual void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) = 0;

    virtual void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) = 0;
};

}

#endif //COSMOGRAPHER_ASPECT_H
