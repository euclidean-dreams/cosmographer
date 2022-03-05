#ifndef COSMOGRAPHER_CLOISTERCOMMUNITY_H
#define COSMOGRAPHER_CLOISTERCOMMUNITY_H

#include "framework/Community.h"

namespace cosmographer {

class Paradigm;

class CloisterCommunity : public Community {
public:
    up<class Cartographer> cartographer;
    up<class AxiomRefresher> axiomRefresher;
    up<class Chromatica> chromatica;

    CloisterCommunity(Paradigm *paradigm) : Community{paradigm} {}
};

}

#endif //COSMOGRAPHER_CLOISTERCOMMUNITY_H