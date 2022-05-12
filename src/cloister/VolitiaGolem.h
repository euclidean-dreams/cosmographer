#ifndef COSMOGRAPHER_VOLITIAGOLEM_H
#define COSMOGRAPHER_VOLITIAGOLEM_H

#include "CloisterCommunity.h"

namespace cosmographer {

class VolitiaGolem : public Fellow<CloisterCommunity> {
public:
    void refresh();
};

}

#endif //COSMOGRAPHER_VOLITIAGOLEM_H
