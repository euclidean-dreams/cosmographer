#ifndef COSMOGRAPHER_CANVAS_H
#define COSMOGRAPHER_CANVAS_H

#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"
#include "primitive/Lattice.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"

namespace cosmographer {

class Canvas : public Illuminable {
public:
    GlimmerCommunity *glimmerCommunity;

    // already tried two lists, slowed the thing down
    umap<Coordinate, HSLColor, CoordinateHash> dots;

    Canvas(
            GlimmerCommunity *glimmerCommunity
    );

    void paint(
            Coordinate locus,
            HSLColor color
    );

    void illuminate(
            Lattice &lattice
    ) override;
};

}

#endif //COSMOGRAPHER_CANVAS_H
