#ifndef COSMOGRAPHER_PAINTERCOMMUNITY_H
#define COSMOGRAPHER_PAINTERCOMMUNITY_H

#include "framework/Community.h"

namespace cosmographer {

class PainterCommunity : public Community, public Constituent {
public:
    PainterCommunity(Paradigm *paradigm) : Community(paradigm) {}

    class Painter *painter;

    class Canvas *canvas;
};

}

#endif //COSMOGRAPHER_PAINTERCOMMUNITY_H
