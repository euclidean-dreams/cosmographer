#ifndef COSMOGRAPHER_SKETCHER_H
#define COSMOGRAPHER_SKETCHER_H

#include "Default.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/Canvas.h"

namespace cosmographer {

class Sketcher : public MicroFellow<GlimmerCommunity> {
private:
    Point location;
    float orientation;
    Canvas *canvasAffinity;

public:
    Sketcher(
            Point location,
            float orientation
    );

    void establishAffinity(
            Canvas *canvas
    );

    void advance(
            float distance
    );

    void rotate(
            float newOrientation
    );
};

}

#endif //COSMOGRAPHER_SKETCHER_H
