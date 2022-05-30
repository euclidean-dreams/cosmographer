#ifndef COSMOGRAPHER_VOLITIAPARADIGMBOND_H
#define COSMOGRAPHER_VOLITIAPARADIGMBOND_H

#include "framework/Minimal.h"

namespace cosmographer {

class VolitiaParadigmBond {
public:
    sp<Arbiter<const Parcel>> arbiter;

    VolitiaParadigmBond(
            sp<Arbiter<const Parcel>> arbiter
    );

    void refresh();
};

}

#endif //COSMOGRAPHER_VOLITIAPARADIGMBOND_H
