#ifndef COSMOGRAPHER_RANDOMIZER_H
#define COSMOGRAPHER_RANDOMIZER_H

#include "CloisterCommunity.h"

namespace cosmographer {

class Randomizer : public Fellow<CloisterCommunity> {
private:
    int generateNumber(int exclusive_max);

public:
    int generate(int exclusive_max);

    float generateProportion();
};

}

#endif //COSMOGRAPHER_RANDOMIZER_H
