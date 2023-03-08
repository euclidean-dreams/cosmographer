#include "Wander.h"
#include "cosmology/glimmering/glimmer/illuminable/painter/Painter.h"

namespace cosmographer {

Wander::Wander(
        GlimmerSoul *glimmerSoul,
        PainterCommunity *painterCommunity
) :
        glimmerSoul{glimmerSoul},
        painterCommunity{painterCommunity} {
}

void Wander::live() {
    auto directive = randomizer->generate(2);
    if (directive == 0) {
        painterCommunity->painter->advance(randomizer->generate(2 * CHAOS_AXIOM), glimmerSoul->color);
    } else if (directive == 1) {
        painterCommunity->painter->rotate(randomizer->generateProportion());
    }
}

}
