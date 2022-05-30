#ifndef COSMOGRAPHER_LUMIONBOOKIE_H
#define COSMOGRAPHER_LUMIONBOOKIE_H

namespace cosmographer {

class LumionBookie {
public:
    int activationCount;
    float maxActivation;

    LumionBookie();

    void recordActivation(float activation);

    void clear();
};

}

#endif //COSMOGRAPHER_LUMIONBOOKIE_H
