#ifndef COSMOGRAPHER_CIRCLE_H
#define COSMOGRAPHER_CIRCLE_H

#include "cosmology/aspect/glimmering/glimmer/GlimmerCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"

namespace cosmographer {

class Circle : public Illuminable {
public:
    GlimmerCommunity *glimmerCommunity;

    Circle(
            GlimmerCommunity *glimmerCommunity
    );

    void illuminate(
            Lattice &lattice
    ) override;
};

}

#endif //COSMOGRAPHER_CIRCLE_H
