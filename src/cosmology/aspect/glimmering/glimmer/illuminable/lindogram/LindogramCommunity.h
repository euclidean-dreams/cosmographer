#ifndef COSMOGRAPHER_LINDOGRAMCOMMUNITY_H
#define COSMOGRAPHER_LINDOGRAMCOMMUNITY_H

#include "Default.h"

namespace cosmographer {

class LindogramCommunity : public Community {
public:
    ~LindogramCommunity() {
        int a = 10;
    }

    up<class Painter> painter;
    up<class Canvas> canvas;
};

}

#endif //COSMOGRAPHER_LINDOGRAMCOMMUNITY_H
