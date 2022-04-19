#include "Curve.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"

namespace cosmographer {

Curve::Curve(
        GlimmerSoul *glimmerSoul,
        PainterCommunity *painterCommunity,
        float initialOrientation,
        float spin
) :
        glimmerSoul{glimmerSoul},
        painterCommunity{painterCommunity},
        initialOrientation{initialOrientation},
        spin{spin} {
}

void Curve::live() {
    if (glimmerSoul->age == 0) {
        painterCommunity->painter->rotate(initialOrientation);
    }
    painterCommunity->painter->advance(1, glimmerSoul->color);
    painterCommunity->painter->advance(1, glimmerSoul->color);
    painterCommunity->painter->rotate(spin);
}

}
