#ifndef COSMOGRAPHER_SIGNALARIUM_H
#define COSMOGRAPHER_SIGNALARIUM_H

#include "CloisterCommunity.h"
#include "primitive/Signal.h"

namespace cosmographer {

class Signalarium : public Fellow<CloisterCommunity> {
public:
    up<Parcel> essentiaParcel;
    const Essentia *essentia;
    Signal stft;

    Signalarium();

    void refresh(up<Parcel> parcel);
};

}

#endif //COSMOGRAPHER_SIGNALARIUM_H
