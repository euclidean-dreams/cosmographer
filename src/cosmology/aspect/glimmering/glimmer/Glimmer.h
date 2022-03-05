#ifndef COSMOGRAPHER_GLIMMER_H
#define COSMOGRAPHER_GLIMMER_H

#include "GlimmerCommunity.h"
#include "cosmology/aspect/glimmering/GlimmeringCommunity.h"
#include "ephemera/Ephemera.h"
#include "illuminable/Illuminable.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Glimmer : public Fellow<GlimmeringCommunity>,  public Liaison<GlimmerCommunity> {
public:
    Glimmer(
            Paradigm *paradigm,
            up<Ephemera> ephemera,
            up<Illuminable> illuminable,
            Point locus,
            HSLColor color,
            float size
    );

    bool illuminate(
            Lattice &lattice
    );
};

}

#endif //COSMOGRAPHER_GLIMMER_H
