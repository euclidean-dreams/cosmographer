#ifndef COSMOGRAPHER_PARADIGM_H
#define COSMOGRAPHER_PARADIGM_H

#include "framework/Libs.h"
#include "framework/Macros.h"
#include "cloister/CloisterCommunity.h"

namespace cosmographer {

class Paradigm : public NonCopyable {
public:
    up<CloisterCommunity> cloister;
    vec<float> axioms;
    uint latticeWidth;
    uint latticeHeight;
};

}

#endif //COSMOGRAPHER_PARADIGM_H
