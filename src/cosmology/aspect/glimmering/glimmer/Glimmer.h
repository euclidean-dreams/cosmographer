#ifndef COSMOGRAPHER_GLIMMER_H
#define COSMOGRAPHER_GLIMMER_H

#include "GlimmerCommunity.h"
#include "cosmology/aspect/glimmering/GlimmeringCommunity.h"
#include "ephemera/Ephemera.h"
#include "terminus/Terminus.h"
#include "illuminable/Illuminable.h"
#include "cosmology/aspect/glimmering/glimmer/ephemera/lindogram/Sketcher.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Glimmer : public Fellow<GlimmeringCommunity>, public Liaison<GlimmerCommunity> {
public:
    Glimmer(
            Paradigm *paradigm,
            up<Illuminable> illuminable,
            Point locus,
            HSLColor color,
            float size
    );

    void live();

    bool shouldTerminate();

    void illuminate(
            Lattice &lattice
    );

    void addTerminus(up<Terminus> terminus);

    void addEphemera(up<Ephemera> ephemera);
};

}

#endif //COSMOGRAPHER_GLIMMER_H
