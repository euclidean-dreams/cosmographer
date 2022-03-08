#ifndef COSMOGRAPHER_DRIFT_H
#define COSMOGRAPHER_DRIFT_H

#include "Ephemera.h"

namespace cosmographer {

class Drift : public Ephemera {
public:
    float inclinationOffset;

    Drift(
            float inclinationOffset
    );

    void live() override;
};
}

#endif //COSMOGRAPHER_DRIFT_H
