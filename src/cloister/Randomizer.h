#ifndef COSMOGRAPHER_RANDOMIZER_H
#define COSMOGRAPHER_RANDOMIZER_H

#include <random>
#include "CloisterCommunity.h"

namespace cosmographer {

class Randomizer : public Fellow<CloisterCommunity> {
private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

    int generateNumber(int exclusive_max);

public:
    Randomizer();

    int generate(int exclusive_max);

    float generateProportion();
};

}

#endif //COSMOGRAPHER_RANDOMIZER_H
