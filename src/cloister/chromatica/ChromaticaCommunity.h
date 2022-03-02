#ifndef COSMOGRAPHER_CHROMATICACOMMUNITY_H
#define COSMOGRAPHER_CHROMATICACOMMUNITY_H

#include "framework/Framework.h"

namespace cosmographer {

class ChromaticaCommunity : public Community {
public:
    up<class Palette> palette;
    up<class ColorPixie> colorPixie;
};

}

#endif //COSMOGRAPHER_CHROMATICACOMMUNITY_H
