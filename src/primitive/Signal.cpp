#include "Signal.h"

namespace cosmographer {

Signal::Signal(
        int size
) :
        samples{},
        energy{0} {
    samples.reserve(size);
}

void Signal::addSample(
        float sample
) {
    samples.push_back(sample);
    energy += sample;
}

float Signal::getSample(int index) {
    return samples[index];
}

}
