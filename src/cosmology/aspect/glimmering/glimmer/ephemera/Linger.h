#ifndef COSMOGRAPHER_LINGER_H
#define COSMOGRAPHER_LINGER_H

#include "Ephemera.h"

namespace cosmographer {

class Linger : public Ephemera {
public:
    bool lighten;

    Linger(
            bool lighten
    );

    void live() override;

    bool isAlive() override;
};

}

#endif //COSMOGRAPHER_LINGER_H
