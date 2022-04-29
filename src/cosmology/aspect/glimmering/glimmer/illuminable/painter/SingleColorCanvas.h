#ifndef COSMOGRAPHER_SINGLECOLORCANVAS_H
#define COSMOGRAPHER_SINGLECOLORCANVAS_H

#include "Canvas.h"

namespace cosmographer {

class SingleColorCanvas : public Canvas {
public:
    SingleColorCanvas(GlimmerSoul *glimmerSoul);

    void illuminate(Lattice &lattice) override;

};

}

#endif //COSMOGRAPHER_SINGLECOLORCANVAS_H
