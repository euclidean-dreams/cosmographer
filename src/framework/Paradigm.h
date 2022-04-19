#ifndef COSMOGRAPHER_PARADIGM_H
#define COSMOGRAPHER_PARADIGM_H

#include "framework/Libs.h"
#include "framework/Macros.h"
#include "cloister/CloisterCommunity.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class Paradigm : public NonCopyable {
public:
    up<CloisterCommunity> cloister;
    vec<float> axioms;
    int microMode;
    int macroMode;
};

extern up<Paradigm> paradigmWrapper;
extern Paradigm *paradigm;

}

#endif //COSMOGRAPHER_PARADIGM_H
