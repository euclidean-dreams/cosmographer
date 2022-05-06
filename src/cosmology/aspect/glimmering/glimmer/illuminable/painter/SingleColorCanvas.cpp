#include "SingleColorCanvas.h"

namespace cosmographer {

SingleColorCanvas::SingleColorCanvas(GlimmerSoul *glimmerSoul) :
        Canvas(glimmerSoul) {

}

void SingleColorCanvas::illuminate(Lattice &lattice) {
    for (auto &dot: dots) {
        auto x = dot.first.x + glimmerSoul->locus.x;
        auto y = dot.first.y + glimmerSoul->locus.y;
        if (lattice.isValid(x, y)) {
            lattice.setColor(x, y, glimmerSoul->color);
        }
    }
}

}
