#ifndef COSMOGRAPHER_EPHEMERA_H
#define COSMOGRAPHER_EPHEMERA_H

#include <ImpresarioUtils.h>
#include "gizmo/Lattice.h"

namespace cosmographer {

class Ephemera : public impresarioUtils::NonCopyable {
protected:
    int age;

public:
    Ephemera();

    void incrementAge();

    virtual void live(Lattice &lattice) = 0;

    virtual bool isDead() = 0;
};

}

#endif //COSMOGRAPHER_EPHEMERA_H
