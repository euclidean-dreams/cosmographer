#ifndef COSMOGRAPHER_COSMOGRAPHER_H
#define COSMOGRAPHER_COSMOGRAPHER_H

#include "CosmographerCommunity.h"
#include "vantage/PalantirVantage.h"
#include "cosmology/Cosmology.h"

namespace cosmographer {

class Cosmographer : public Liaison<CosmographerCommunity>, public Circulable {
private:
    up<Paradigm> paradigm;

    vec<up<Parcel>> receiveEssentiaParcelBundle();

public:
    Cosmographer(
            zmq::context_t &zmqContext,
            Paradigm *paradigm,
            sp<BufferArbiter<const Parcel>> phenomenology
    );

    void activate() override;
};

}

#endif //COSMOGRAPHER_COSMOGRAPHER_H
