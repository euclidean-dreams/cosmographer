#ifndef COSMOGRAPHER_CANVAS_H
#define COSMOGRAPHER_CANVAS_H

#include "Illuminable.h"

namespace cosmographer {

class Canvas : public Illuminable {
public:
    vec<Point> points;

    void draw(
            Point point
    );

    void illuminate(Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_CANVAS_H
