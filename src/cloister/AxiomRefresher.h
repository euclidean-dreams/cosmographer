#ifndef COSMOGRAPHER_AXIOMREFRESHER_H
#define COSMOGRAPHER_AXIOMREFRESHER_H

#include "CloisterCommunity.h"

namespace cosmographer {

class AxiomRefresher : public Fellow<CloisterCommunity> {
public:
    sp<Arbiter<const Parcel>> axiomArbiter;

    AxiomRefresher(
            sp<Arbiter<const Parcel>> axiomArbiter
    );

    void refresh();
};

}

#endif //COSMOGRAPHER_AXIOMREFRESHER_H
