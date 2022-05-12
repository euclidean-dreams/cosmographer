#ifndef COSMOGRAPHER_SIGNALAVERAGE_H
#define COSMOGRAPHER_SIGNALAVERAGE_H

#include "framework/Minimal.h"

namespace cosmographer {

class SignalAverage {
private:
    lst<float> samples;
    float sum;
    size_t desiredSize;

public:
    float value;

    explicit SignalAverage(size_t size);

    void addSample(float sample);
};

}

#endif //COSMOGRAPHER_SIGNALAVERAGE_H
