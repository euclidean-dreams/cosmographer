#ifndef COSMOGRAPHER_GLIMMERSOUL_H
#define COSMOGRAPHER_GLIMMERSOUL_H

#include "Default.h"
#include "primitive/Loci.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class Lumion;

class GlimmerSoul : public Element {
public:
    Lumion *lumion;
    Point locus;
    HSLColor color;
    int age;
    bool alive;

    GlimmerSoul(
            Lumion *lumion,
            Point locus,
            HSLColor color,
            float size
    ) :
            lumion{lumion},
            locus{locus},
            color{color},
            age{0},
            alive{true} {

    }
};

}

#endif //COSMOGRAPHER_GLIMMERSOUL_H
