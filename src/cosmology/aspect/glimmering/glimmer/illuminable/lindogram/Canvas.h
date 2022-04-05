#ifndef COSMOGRAPHER_CANVAS_H
#define COSMOGRAPHER_CANVAS_H

#include "LindogramCommunity.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Canvas : public Fellow<LindogramCommunity> {
public:
    umap<Point, HSLColor, PointHash> dots;

    void paint(
            Point point,
            HSLColor color
    );

    void show(
            Lattice &lattice,
            Point locus
    );
};

}

#endif //COSMOGRAPHER_CANVAS_H
