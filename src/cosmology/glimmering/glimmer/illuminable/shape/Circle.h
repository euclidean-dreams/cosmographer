#ifndef COSMOGRAPHER_CIRCLE_H
#define COSMOGRAPHER_CIRCLE_H

#include "cosmology/glimmering/glimmer/GlimmerSoul.h"
#include "cosmology/glimmering/glimmer/illuminable/Illuminable.h"

namespace cosmographer {

class Circle : public Illuminable {
public:
    GlimmerSoul *glimmerSoul;

    Circle(
            GlimmerSoul *glimmerSoul
    );

    void illuminate(
            Lattice &lattice
    ) override;
};

}

#endif //COSMOGRAPHER_CIRCLE_H
