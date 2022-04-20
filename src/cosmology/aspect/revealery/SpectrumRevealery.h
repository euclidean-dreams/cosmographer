#ifndef COSMOGRAPHER_SPECTRUMREVEALERY_H
#define COSMOGRAPHER_SPECTRUMREVEALERY_H

#include "Revealery.h"
#include "oddments/SimpleMovingAverage.h"

namespace cosmographer {

class SpectrumRevealery : public Revealery {
public:
    void reveal(
            LumionExcitation excitation
    ) override;
};

}
#endif //COSMOGRAPHER_SPECTRUMREVEALERY_H
