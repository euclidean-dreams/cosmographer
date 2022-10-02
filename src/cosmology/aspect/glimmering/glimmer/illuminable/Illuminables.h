#pragma once

#include "Default.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerSoul.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"

namespace PROJECT_NAMESPACE {

class Dot : public Illuminable {
public:
    GlimmerSoul *glimmerSoul;

    Dot(
            GlimmerSoul *glimmerSoul
    ) :
            glimmerSoul{glimmerSoul} {

    }

    void illuminate(
            Lattice &lattice
    ) {
        if (lattice.isValid(glimmerSoul->locus.x, glimmerSoul->locus.y)) {
            lattice.setColor(glimmerSoul->locus.x, glimmerSoul->locus.y, glimmerSoul->color);
        }
    }
};

}
