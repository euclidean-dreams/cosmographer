#ifndef COSMOGRAPHER_GLIMMER_H
#define COSMOGRAPHER_GLIMMER_H

#include "cosmology/aspect/glimmering/GlimmeringCommunity.h"
#include "GlimmerCommunity.h"
#include "cosmology/aspect/glimmering/glimmer/lively//Lively.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Glimmer : public Fellow<GlimmeringCommunity> {
public:
    GlimmerCommunity *glimmerCommunity;
    vec<up<Constituent>> constituents;
    vec<Lively *> livelies;
    vec<Illuminable *> illuminables;

    Glimmer(
            GlimmeringCommunity *glimmeringCommunity,
            Point locus,
            HSLColor color,
            int size
    );

    void live();

    bool shouldTerminate();

    void illuminate(
            Lattice &lattice
    );

    void addLively(up<Lively> lively);

    void addIlluminable(up<Illuminable> illuminable);
};

}

#endif //COSMOGRAPHER_GLIMMER_H
