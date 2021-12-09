#ifndef COSMOGRAPHER_ILLUMINABLE_H
#define COSMOGRAPHER_ILLUMINABLE_H

#include <ImpresarioUtils.h>
#include "gizmo/CoordinateTransformer.h"
#include "gizmo/color/Colorology.h"
#include "gizmo/Lattice.h"

namespace cosmographer {

class Illuminable : public impresarioUtils::NonCopyable {
protected:
    Coordinate origin;
    HSLColor soulColor;
    int age;

public:
    explicit Illuminable(HSLColor soulColor);

    Illuminable(Coordinate origin, HSLColor soulColor);

    virtual void illuminate(Lattice &lattice) = 0;
};

}

#endif //COSMOGRAPHER_ILLUMINABLE_H
