#ifndef COSMOGRAPHER_LUMIONBOOKIE_H
#define COSMOGRAPHER_LUMIONBOOKIE_H

namespace cosmographer {

class LumionBookie {
public:
    int activationCount;
    float maxExcitation;

    LumionBookie();

    void recordExcitation(float magnitude);

    void clear();
};

}

#endif //COSMOGRAPHER_LUMIONBOOKIE_H
