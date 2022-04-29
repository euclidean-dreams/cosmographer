#include "Wander.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"

namespace cosmographer {

Wander::Wander(
        GlimmerSoul *glimmerSoul,
        PainterCommunity *painterCommunity
) :
        glimmerSoul{glimmerSoul},
        painterCommunity{painterCommunity} {
}

void Wander::live() {
    auto directive = RANDOM.generate(2);
    if (directive == 0) {
        painterCommunity->painter->advance(RANDOM.generate(10 * CHAOS_AXIOM), glimmerSoul->color);
    } else if (directive == 1) {
        painterCommunity->painter->rotate(RANDOM.generateProportion());
    }
}

}
