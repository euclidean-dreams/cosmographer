#ifndef COSMOGRAPHER_COSMOLOGY_H
#define COSMOGRAPHER_COSMOLOGY_H

#include <ImpresarioUtils.h>
#include "Config.h"
#include "cosmology/Lattice.h"
#include "cosmology/aspect/Aspect.h"
#include "cosmology/aspect/SeedAspect.h"

namespace cosmographer {

class Cosmology : public impresarioUtils::NonCopyable {
private:
    std::unique_ptr<Aspect> aspect;
    int tick;

public:
    Cosmology();

    std::unique_ptr<Lattice> observe();

    void alter(const impresarioUtils::Packet &packet);
};

}

#endif //COSMOGRAPHER_COSMOLOGY_H
