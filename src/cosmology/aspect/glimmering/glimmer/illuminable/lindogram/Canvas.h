#ifndef COSMOGRAPHER_CANVAS_H
#define COSMOGRAPHER_CANVAS_H

#include "LindogramCommunity.h"
#include "primitive/Lattice.h"

namespace cosmographer {

// already tried two lists, slowed the thing down

class Canvas : public Fellow<LindogramCommunity> {
public:
    umap<Coordinate, HSLColor, CoordinateHash> dots;

    void paint(
            Coordinate locus,
            HSLColor color
    );

    void show(
            Lattice &lattice,
            Coordinate locus
    );
};

}

#endif //COSMOGRAPHER_CANVAS_H
