#ifndef COSMOGRAPHER_PAINTER_H
#define COSMOGRAPHER_PAINTER_H

#include "Default.h"
#include "Canvas.h"
#include "LindogramCommunity.h"

namespace cosmographer {

class Painter : public Fellow<LindogramCommunity> {
private:
    Point location;
    float orientation;

public:
    Painter();

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
