#ifndef COSMOGRAPHER_GLIMMERING_H
#define COSMOGRAPHER_GLIMMERING_H

#include "GlimmeringCommunity.h"
#include "cosmology/aspect/AspectCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/glimmering/revealery/Revealery.h"
#include "cosmology/aspect/mesh/lumion/Lumion.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Glimmering : public Fellow<AspectCommunity>,  public Liaison<GlimmeringCommunity> {
public:
    Glimmering(
            AspectCommunity *community,
            up<Revealery> revealery
    );

    void excite(
            LumionExcitation excitation
    );

    void illuminate(
            Lattice &lattice
    );
};

}

#endif //COSMOGRAPHER_GLIMMERING_H
