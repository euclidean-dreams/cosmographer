#ifndef COSMOGRAPHER_DRAGONCURVE_H
#define COSMOGRAPHER_DRAGONCURVE_H

#include "cosmology/aspect/glimmering/glimmer/ephemera/Ephemera.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/Canvas.h"
#include "Sketcher.h"

namespace cosmographer {

class DragonCurve : public Ephemera {
public:
    Sketcher sketcher;

    void live() override;
};

}

#endif //COSMOGRAPHER_DRAGONCURVE_H
