#ifndef COSMOGRAPHER_GLIMMER_H
#define COSMOGRAPHER_GLIMMER_H

#include "cosmology/aspect/glimmering/GlimmeringCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/lively//Lively.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"
#include "cosmology/aspect/glimmering/glimmer/terminable/Terminable.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Glimmer : public Fellow<GlimmeringCommunity> {
public:
    vec<up<Constituent>> constituents;
    vec<Lively *> livelies;
    vec<Terminable *> terminbles;
    vec<Illuminable *> illuminables;

    void live();

    bool shouldTerminate();

    void illuminate(
            Lattice &lattice
    );
};

}

#endif //COSMOGRAPHER_GLIMMER_H
