#ifndef COSMOGRAPHER_GLIMMERCOMMUNITY_H
#define COSMOGRAPHER_GLIMMERCOMMUNITY_H

#include "Default.h"
#include "primitive/Loci.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class GlimmerCommunity : public Community, public Constituent {
public:
    GlimmerCommunity(Paradigm *paradigm) : Community(paradigm) {}

    Point locus;
    HSLColor color;
    float size;
    int age = 0;
    bool alive = true;
};

}

#endif //COSMOGRAPHER_GLIMMERCOMMUNITY_H
