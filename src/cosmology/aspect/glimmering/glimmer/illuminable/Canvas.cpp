#include "Canvas.h"

namespace cosmographer {

void Canvas::draw(
        Point point
) {
    points.push_back(point);
}

void Canvas::illuminate(Lattice &lattice) {
    for (int i = 0; i < points.size(); i++) {
        auto &point = points[i];
        if (lattice.isValid(point.x, point.y)) {
            lattice.setColor(point.x, point.y, community->color);
        }
    }
}

}
