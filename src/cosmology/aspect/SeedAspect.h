#ifndef COSMOGRAPHER_SEEDASPECT_H
#define COSMOGRAPHER_SEEDASPECT_H

#include "Aspect.h"
#include "Config.h"

namespace cosmographer {

class SeedAspect : public Aspect {
private:
    int x;
    int y;

public:
    SeedAspect();

    std::unique_ptr<Lattice> manifest(int tick) override;

    void alter(const impresarioUtils::Packet &packet) override;
};

}

#endif //COSMOGRAPHER_SEEDASPECT_H
