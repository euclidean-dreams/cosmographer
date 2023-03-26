#ifndef COSMOGRAPHER_LUMIONMIMIC_H
#define COSMOGRAPHER_LUMIONMIMIC_H

#include "Lively.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/GlimmerSoul.h"

namespace cosmographer {

class LumionMimic : public Lively {
public:
    GlimmerSoul *glimmerSoul;

    LumionMimic(
            GlimmerSoul *glimmerSoul
    ) :
            glimmerSoul{glimmerSoul} {}

    void live() override {
//        if (!glimmerSoul->lumion->excited) {
//            glimmerSoul->alive = false;
//        }
//        if (glimmerSoul->age > 0) {
//            glimmerSoul->alive = false;
//        }
    }
};

}

#endif //COSMOGRAPHER_LUMIONMIMIC_H
