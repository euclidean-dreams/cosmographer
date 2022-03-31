#ifndef COSMOGRAPHER_SIGNAL_H
#define COSMOGRAPHER_SIGNAL_H

#include "framework/Minimal.h"

namespace cosmographer {

class Signal {
private:
    vec<float> samples;

public:
    float energy;

    Signal(
            int size
    );

    void addSample(
            float sample
    );

    float getSample(
            int index
    );
};

}

#endif //COSMOGRAPHER_SIGNAL_H
