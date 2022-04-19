#ifndef COSMOGRAPHER_GLIMMERSOUL_H
#define COSMOGRAPHER_GLIMMERSOUL_H

#include "Default.h"
#include "primitive/Loci.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class GlimmerSoul : public Element {
public:
    Point locus = {0, 0};
    HSLColor color = {0, 0, 0};
    float size = 0;
    int age = 0;
    bool alive = true;
};

}

#endif //COSMOGRAPHER_GLIMMERSOUL_H
