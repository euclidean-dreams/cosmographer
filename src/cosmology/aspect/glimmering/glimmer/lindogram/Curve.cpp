#include "Curve.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"

namespace cosmographer {

Curve::Curve(
        GlimmerCommunity *glimmerCommunity,
        PainterCommunity *painterCommunity,
        float initialOrientation,
        float spin
) :
        glimmerCommunity{glimmerCommunity},
        painterCommunity{painterCommunity},
        initialOrientation{initialOrientation},
        spin{spin} {
}

void Curve::live() {
    if (glimmerCommunity->age == 0) {
        painterCommunity->painter->rotate(initialOrientation);
    }
    painterCommunity->painter->advance(1, glimmerCommunity->color);
    painterCommunity->painter->advance(1, glimmerCommunity->color);
    painterCommunity->painter->rotate(spin);
}

}
