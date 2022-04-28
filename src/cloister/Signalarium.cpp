#include "Signalarium.h"
#include "Default.h"

namespace cosmographer {

Signalarium::Signalarium(

) :
        essentiaParcel{},
        essentia{},
        stft{0} {

}

void Signalarium::refresh(
        up<Parcel> parcel
) {
    essentiaParcel = mv(parcel);
    essentia = Unwrap::Essentia(*essentiaParcel);
    auto samples = essentia->stft();
    stft = {cast(int, samples->size())};
    for (int index = 0; index < samples->size(); index++) {
        auto sample = samples->Get(index);
        stft.addSample(sample);
    }
}

}
