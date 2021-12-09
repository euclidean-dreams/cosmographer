#ifndef COSMOGRAPHER_EPHEMERA_H
#define COSMOGRAPHER_EPHEMERA_H

#include <ImpresarioUtils.h>
#include "gizmo/CoordinateTransformer.h"
#include "gizmo/color/Colorology.h"
#include "gizmo/Lattice.h"

namespace cosmographer {

class Ephemera : public impresarioUtils::NonCopyable {
protected:
    Coordinate origin;
    HSLColor soulColor;
    int age;

public:
    explicit Ephemera(HSLColor soulColor);

    Ephemera(Coordinate origin, HSLColor soulColor);

    void incrementAge();

    Coordinate getOrigin();

    virtual void live(Lattice &lattice) = 0;

    virtual bool isDead() = 0;
};

}

#endif //COSMOGRAPHER_EPHEMERA_H
