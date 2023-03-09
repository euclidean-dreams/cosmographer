#ifndef COSMOGRAPHER_CANVAS_H
#define COSMOGRAPHER_CANVAS_H

#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/Illuminable.h"
#include "primitive/Lattice.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class Canvas : public Illuminable {
public:
    GlimmerSoul *glimmerSoul;

    // already tried two lists, slowed the thing down
    umap<Coordinate, HSLColor, CoordinateHash> dots;

    Canvas(
            GlimmerSoul *glimmerSoul
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
