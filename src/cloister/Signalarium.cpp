#include "Signalarium.h"
#include "Default.h"

namespace cosmographer {

Signalarium::Signalarium(

) :
        essentiaParcel{},
        essentia{},
        stft{0},
        equalized{0} {

}

void Signalarium::refresh(
        up<Parcel> parcel
) {
    essentiaParcel = mv(parcel);
    essentia = Unwrap::Essentia(*essentiaParcel);
    auto samples = essentia->stft();
    stft = {cast(int, samples->size())};
    for (auto sample: *samples) {
        stft.addSample(sample);
    }
    samples = essentia->equalized();
    equalized = {cast(int, samples->size())};
    for (auto sample: *samples) {
        equalized.addSample(sample);
    }
}

}
