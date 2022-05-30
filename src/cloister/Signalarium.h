#ifndef COSMOGRAPHER_SIGNALARIUM_H
#define COSMOGRAPHER_SIGNALARIUM_H

#include "primitive/Signal.h"

namespace cosmographer {

class Signalarium {
public:
    up<Parcel> essentiaParcel;
    const Essentia *essentia;
    Signal stft;

    Signalarium();

    void refresh(up<Parcel> parcel);
};

}

#endif //COSMOGRAPHER_SIGNALARIUM_H
