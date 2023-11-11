#ifndef COSMOGRAPHER_RECTANGLE_H
#define COSMOGRAPHER_RECTANGLE_H

#include "cosmology/revealeryAspect/glimmering/glimmer/GlimmerSoul.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/Illuminable.h"

namespace cosmographer {

class Rectangle : public Illuminable {
public:
    GlimmerSoul *glimmerSoul;
    int heightRatio;

    Rectangle(
            GlimmerSoul *glimmerSoul,
            int heightRatio
    );

    void illuminate(
            Lattice &lattice
    ) override;
};

}

#endif //COSMOGRAPHER_RECTANGLE_H
