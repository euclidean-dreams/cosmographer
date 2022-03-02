#include "Lumion.h"

namespace cosmographer {

Lumion::Lumion(
        int signalIndex,
        Point latticePoint
) :
        signalIndex{signalIndex},
        latticePoint{latticePoint} {

}

LumionExcitation Lumion::excite(
        vec<float> &signal
) {
    auto normalizationScale = LUMION_EXCITATION_AXIOM;
    auto sample = signal[signalIndex];
    auto normalizedSample = 1 - 1 / (std::pow(sample / (-1 * (10000 - 10000 * normalizationScale)), 2) + 1);
    return LumionExcitation{
            latticePoint,
            cast(float, normalizedSample)
    };
}

}
