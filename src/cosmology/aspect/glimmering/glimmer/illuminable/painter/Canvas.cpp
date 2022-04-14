#include "Canvas.h"
#include "Painter.h"

namespace cosmographer {

Canvas::Canvas(
        GlimmerCommunity *glimmerCommunity
) :
        glimmerCommunity{glimmerCommunity},
        dots{} {

}

void Canvas::paint(
        Coordinate locus,
        HSLColor color
) {
    dots.insert_or_assign(locus, color);
}

void Canvas::illuminate(
        Lattice &lattice
) {
    for (auto &dot: dots) {
        auto x = dot.first.x + glimmerCommunity->locus.x;
        auto y = dot.first.y + glimmerCommunity->locus.y;
        if (lattice.isValid(x, y)) {
            lattice.setColor(x, y, dot.second);
        }
    }
}

}
