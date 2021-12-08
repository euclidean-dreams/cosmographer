#ifndef COSMOGRAPHER_EMPYRIUM_H
#define COSMOGRAPHER_EMPYRIUM_H

#include <ImpresarioUtils.h>
#include "cosmology/Cosmology.h"

namespace cosmographer {

class Empyrium : public impresarioUtils::Circulable {
private:
    std::shared_ptr<Cosmology> cosmology;
    int tickInterval;

public:
    explicit Empyrium(std::shared_ptr<Cosmology> cosmology);

    void activate() override;

    uint64_t getTickInterval() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_EMPYRIUM_H
