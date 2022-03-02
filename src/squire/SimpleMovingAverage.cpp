#include "SimpleMovingAverage.h"

namespace cosmographer {

SimpleMovingAverage::SimpleMovingAverage(uint size)
        : samples{} {
    samples.resize(size, 0);
}

void SimpleMovingAverage::addSample(float sample) {
    samples[oldestSampleIndex] = sample;
    oldestSampleIndex++;
    if (oldestSampleIndex > samples.size()) {
        oldestSampleIndex = 0;
    }
}

float SimpleMovingAverage::calculate() {
    auto sum = 0;
    for (auto sample: samples) {
        sum += sample;
    }
    auto mean = sum / samples.size();
    return mean;
}

}
