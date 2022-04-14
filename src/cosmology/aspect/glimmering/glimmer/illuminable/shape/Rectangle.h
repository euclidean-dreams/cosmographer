#ifndef COSMOGRAPHER_RECTANGLE_H
#define COSMOGRAPHER_RECTANGLE_H

#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"

namespace cosmographer {

class Rectangle : public Illuminable {
public:
    GlimmerCommunity *glimmerCommunity;
    int heightRatio;

    Rectangle(
            GlimmerCommunity *glimmerCommunity,
            int heightRatio
    );

    void illuminate(
            Lattice &lattice
    ) override;
};

}

#endif //COSMOGRAPHER_RECTANGLE_H
