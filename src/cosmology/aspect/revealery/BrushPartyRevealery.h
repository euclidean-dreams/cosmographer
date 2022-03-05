#ifndef COSMOGRAPHER_BRUSHPARTYREVEALERY_H
#define COSMOGRAPHER_BRUSHPARTYREVEALERY_H

#include "Revealery.h"

namespace cosmographer {

class BrushPartyRevealery : public Revealery {
public:
    void reveal(
            LumionExcitation excitation
    ) override;
};

}

#endif //COSMOGRAPHER_BRUSHPARTYREVEALERY_H
