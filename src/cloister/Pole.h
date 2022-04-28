#ifndef COSMOGRAPHER_POLE_H
#define COSMOGRAPHER_POLE_H

#include "CloisterCommunity.h"

namespace cosmographer {

class Pole : public Fellow<CloisterCommunity> {
public:
    float pole;
    bool deltaDirection;

    Pole();

    void refresh();
};

}

#endif //COSMOGRAPHER_POLE_H
