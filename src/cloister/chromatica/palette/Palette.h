#ifndef COSMOGRAPHER_PALETTE_H
#define COSMOGRAPHER_PALETTE_H

#include "Default.h"
#include "cloister/chromatica/ChromaticaCommunity.h"
#include "cloister/ColorPixie.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class Palette : public Fellow<ChromaticaCommunity> {
public:
    virtual HSLColor getColor() = 0;

    virtual void experienceEssentia() {};
};

}

#endif //COSMOGRAPHER_PALETTE_H
