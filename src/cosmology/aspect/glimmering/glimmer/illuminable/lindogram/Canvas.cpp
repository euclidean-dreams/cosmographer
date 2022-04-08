#include "Canvas.h"
#include "Painter.h"

namespace cosmographer {

void Canvas::paint(
        Coordinate locus,
        HSLColor color
) {
    dots.insert_or_assign(locus, color);
}

void Canvas::show(
        Lattice &lattice,
        Coordinate locus
) {
    for (auto &dot: dots) {
        auto x = dot.first.x + locus.x;
        auto y = dot.first.y + locus.y;
        if (lattice.isValid(x, y)) {
            lattice.setColor(x, y, dot.second);
        }
    }
}

}
