#ifndef COSMOGRAPHER_GLIMMERING_H
#define COSMOGRAPHER_GLIMMERING_H

#include "GlimmeringCommunity.h"
#include "cosmology/aspect/AspectCommunity.h"
#include "cosmology/aspect/revealery/Revealery.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/mesh/lumion/Lumion.h"
#include "primitive/Lattice.h"
#include "Illuminator.h"
#include "Orchestrator.h"

namespace cosmographer {

class Glimmering : public Fellow<AspectCommunity>, public Liaison<GlimmeringCommunity> {
public:
    Glimmering(
            AspectCommunity *community
    );

    void illuminate(
            Lattice &lattice
    );

    void addGlimmer(
            up<Glimmer> glimmer
    );
};

}

#endif //COSMOGRAPHER_GLIMMERING_H
