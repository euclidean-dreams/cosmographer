#ifndef COSMOGRAPHER_SIMPLEMOVINGAVERAGE_H
#define COSMOGRAPHER_SIMPLEMOVINGAVERAGE_H

#include "framework/Minimal.h"

namespace cosmographer {

class SimpleMovingAverage {
private:
    lst<float> samples;
    float currentValue;

public:
    explicit SimpleMovingAverage(uint size);

    void addSample(float sample);

    float calculate();
};

}

#endif //COSMOGRAPHER_SIMPLEMOVINGAVERAGE_H
