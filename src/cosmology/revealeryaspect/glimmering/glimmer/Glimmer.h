#ifndef COSMOGRAPHER_GLIMMER_H
#define COSMOGRAPHER_GLIMMER_H

#include "cosmology/revealeryaspect/glimmering/GlimmeringCommunity.h"
#include "GlimmerSoul.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/Illuminable.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class Glimmer : public Fellow<GlimmeringCommunity> {
public:
    GlimmerSoul *glimmerSoul;
    vec<up<Element>> constituents;
    vec<Lively *> livelies;
    vec<Illuminable *> illuminables;

    Glimmer(
            GlimmeringCommunity *glimmeringCommunity,
            up<GlimmerSoul> glimmerSoulWrapper
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
