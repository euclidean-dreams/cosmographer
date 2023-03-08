#include "Triangle.h"
#include "cosmology/glimmering/glimmer/illuminable/painter/Painter.h"

namespace cosmographer {

Triangle::Triangle(
        GlimmerSoul *glimmerSoul,
        PainterCommunity *painterCommunity,
        float initialOrientation
) :
        glimmerSoul{glimmerSoul},
        painterCommunity{painterCommunity},
        initialOrientation{initialOrientation} {
}

void Triangle::live() {
    if (glimmerSoul->age == 0) {
        painterCommunity->painter->rotate(initialOrientation);
        auto edgeLength = 20 * MAGNITUDE_AXIOM;
        for (int edge = 0; edge < 3; edge++) {
            for (int i = 0; i < edgeLength; i++) {
                painterCommunity->painter->advance(1, glimmerSoul->color);
            }
            painterCommunity->painter->rotate(2 * M_PI / 3);
        }
    }
}

}
