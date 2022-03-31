#include "SimpleMovingAverage.h"

namespace cosmographer {

SimpleMovingAverage::SimpleMovingAverage(uint size)
        : samples{} {
    samples.resize(size, 0);
}

void SimpleMovingAverage::addSample(float sample) {
    samples.pop_front();
    samples.push_back(sample);
    auto sum = 0;
    for (auto value: samples) {
        sum += value;
    }
    currentValue = sum / samples.size();
}

float SimpleMovingAverage::calculate() {
    return currentValue;
}

}
