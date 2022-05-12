#ifndef COSMOGRAPHER_VOLITIAGOLEM_H
#define COSMOGRAPHER_VOLITIAGOLEM_H

#include "CloisterCommunity.h"
#include "oddments/SignalAverage.h"

namespace cosmographer {

class VolitiaGolem : public Fellow<CloisterCommunity> {
private:
    SignalAverage averageNonZeroLumionActivationCount;

public:
    VolitiaGolem();

    void refresh();
};

}

#endif //COSMOGRAPHER_VOLITIAGOLEM_H
