#ifndef COSMOGRAPHER_SPECTRUMREVEALERY_H
#define COSMOGRAPHER_SPECTRUMREVEALERY_H

#include "Revealery.h"
#include "oddments/SignalAverage.h"

namespace cosmographer {

class SpectrumRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override;
};

}
#endif //COSMOGRAPHER_SPECTRUMREVEALERY_H
