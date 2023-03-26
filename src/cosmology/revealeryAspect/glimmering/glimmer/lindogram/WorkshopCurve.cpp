#include "WorkshopCurve.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/Painter.h"

namespace cosmographer {

WorkshopCurve::WorkshopCurve(
        GlimmerSoul *glimmerSoul,
        PainterCommunity *painterCommunity,
        float initialOrientation
) :
        glimmerSoul{glimmerSoul},
        painterCommunity{painterCommunity},
        initialOrientation{initialOrientation} {

}

void WorkshopCurve::live() {
    painterCommunity->painter->advance(1, glimmerSoul->color);
    if(glimmerSoul->age % 2 == 0) {
        painterCommunity->painter->rotate(M_PI / 16);
    }
}

}
