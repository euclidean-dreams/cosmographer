#ifndef COSMOGRAPHER_GLIMMERCOMMUNITY_H
#define COSMOGRAPHER_GLIMMERCOMMUNITY_H

#include "Default.h"
#include "primitive/Loci.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class GlimmerCommunity : public Community {
public:
    vec<up<class Ephemera>> ephemera;
    up<class Illuminable> illuminable;
    vec<up<class Terminus>> termini;
    Point locus;
    HSLColor color;
    float size;
    int age;

    // dependency bundle
    up<class Sketcher> sketcher;
};

}

#endif //COSMOGRAPHER_GLIMMERCOMMUNITY_H
