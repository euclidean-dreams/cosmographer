#ifndef COSMOGRAPHER_CLOISTERCOMMUNITY_H
#define COSMOGRAPHER_CLOISTERCOMMUNITY_H

#include "framework/Community.h"

namespace cosmographer {

class CloisterCommunity : public Community {
public:
    up<class Cartographer> cartographer;
    up<class AxiomRefresher> axiomRefresher;
    up<class VolitiaGolem> volitiaGolem;
    up<class Chromatica> chromatica;
    up<class ColorPixie> colorPixie;
    up<class Constants> constants;
    up<class Randomizer> randomizer;
    up<class Signalarium> signalarium;
    up<class Pole> pole;
    up<class LumionBookie> lumionBookie;
};

}

#endif //COSMOGRAPHER_CLOISTERCOMMUNITY_H
