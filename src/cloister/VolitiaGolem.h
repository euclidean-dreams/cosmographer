#ifndef COSMOGRAPHER_VOLITIAGOLEM_H
#define COSMOGRAPHER_VOLITIAGOLEM_H

#include "oddments/SignalAverage.h"

namespace cosmographer {

class VolitiaGolem {
private:
    SignalAverage averageNonZeroLumionActivationCount;

public:
    VolitiaGolem();

    void refresh();
};

}

#endif //COSMOGRAPHER_VOLITIAGOLEM_H
