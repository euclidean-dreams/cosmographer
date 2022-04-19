#ifndef COSMOGRAPHER_PAINTERCOMMUNITY_H
#define COSMOGRAPHER_PAINTERCOMMUNITY_H

#include "framework/Community.h"

namespace cosmographer {

class PainterCommunity : public Community, public Element {
public:
    class Painter *painter;

    class Canvas *canvas;
};

}

#endif //COSMOGRAPHER_PAINTERCOMMUNITY_H
