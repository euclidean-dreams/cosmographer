#ifndef COSMOGRAPHER_ORBREVEALERY_H
#define COSMOGRAPHER_ORBREVEALERY_H

#include "Revealery.h"

namespace cosmographer {

class OrbRevealery  : public Revealery {
public:
    void reveal(
            LumionExcitation excitation
    ) override;
};

}

#endif //COSMOGRAPHER_ORBREVEALERY_H
