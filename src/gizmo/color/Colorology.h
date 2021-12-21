#ifndef COSMOGRAPHER_COLOROLOGY_H
#define COSMOGRAPHER_COLOROLOGY_H

#include "gizmo/paradigm/Paradigm.h"

#define HUE_JITTER 200

namespace cosmographer {

class Colorology {
public:
    static int hueJitter(int hue);
};

}

#endif //COSMOGRAPHER_COLOROLOGY_H
