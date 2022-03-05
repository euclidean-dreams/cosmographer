#ifndef COSMOGRAPHER_GLIMMERCOMMUNITY_H
#define COSMOGRAPHER_GLIMMERCOMMUNITY_H

#include "default.h"
#include "primitive/Loci.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class GlimmerCommunity : public Community {
public:
    up<class Ephemera> ephemera;
    up<class Illuminable> illuminable;
    Point locus;
    HSLColor color;
    float size;
    int age;
};

}

#endif //COSMOGRAPHER_GLIMMERCOMMUNITY_H
