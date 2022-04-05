#include "Canvas.h"
#include "Painter.h"

namespace cosmographer {

void Canvas::paint(
        Point point,
        HSLColor color
) {
    dots.insert_or_assign(point, color);
}

void Canvas::show(
        Lattice &lattice,
        Point locus
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
