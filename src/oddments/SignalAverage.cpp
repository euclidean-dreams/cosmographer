#include "SignalAverage.h"

namespace cosmographer {

SignalAverage::SignalAverage(size_t size)
        : samples{},
        desiredSize{size} {
}

void SignalAverage::addSample(float sample) {
    sum += sample;
    samples.push_back(sample);

    if (samples.size() > desiredSize) {
        sum -= samples.front();
        samples.pop_front();
    }

    value = sum / samples.size();
}

}
