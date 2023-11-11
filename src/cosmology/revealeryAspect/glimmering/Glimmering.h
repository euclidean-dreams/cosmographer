#ifndef COSMOGRAPHER_GLIMMERING_H
#define COSMOGRAPHER_GLIMMERING_H

#include "GlimmeringCommunity.h"
#include "cosmology/revealeryAspect/RevealeryAspectCommunity.h"
#include "cosmology/revealeryAspect/revealery/Revealery.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/revealeryAspect/mesh/lumion/Lumion.h"
#include "primitive/Lattice.h"
#include "Illuminator.h"
#include "Orchestrator.h"

namespace cosmographer {

class Glimmering : public Fellow<RevealeryAspectCommunity>, public Liaison<GlimmeringCommunity> {
public:
    Glimmering(
            RevealeryAspectCommunity *community
    );

    void illuminate(
            Lattice &lattice
    );

    void addGlimmer(
            up<Glimmer> glimmer
    );

    GlimmeringCommunity *fetchSubcommunity();
};

}

#endif //COSMOGRAPHER_GLIMMERING_H
