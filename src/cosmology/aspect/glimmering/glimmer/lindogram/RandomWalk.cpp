#include "RandomWalk.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"

namespace cosmographer {

RandomWalk::RandomWalk(
        GlimmerCommunity *glimmerCommunity,
        PainterCommunity *painterCommunity,
        float initialOrientation,
        float spin
) :
        glimmerCommunity{glimmerCommunity},
        painterCommunity{painterCommunity},
        initialOrientation{initialOrientation},
        spin{spin},
        initialized{false} {
}

void RandomWalk::live() {
    if (!initialized) {
        painterCommunity->painter->rotate(initialOrientation);
        initialized = true;
    }
    painterCommunity->painter->advance(1, glimmerCommunity->color);
    painterCommunity->painter->advance(1, glimmerCommunity->color);
    painterCommunity->painter->rotate(spin / glimmerCommunity->age);
}

}
