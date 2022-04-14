#ifndef COSMOGRAPHER_PAINTER_H
#define COSMOGRAPHER_PAINTER_H

#include "Default.h"
#include "Canvas.h"
#include "PainterCommunity.h"

namespace cosmographer {

class Painter : public Constituent {
public:
    PainterCommunity *painterCommunity;
    Point location;
    float orientation;

    Painter(
            PainterCommunity *painterCommunity
    );

    void advance(
            float distance,
            HSLColor color
    );

    void rotate(
            float newOrientation
    );
};

}

#endif //COSMOGRAPHER_PAINTER_H
