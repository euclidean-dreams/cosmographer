#include "Fuzz.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"

namespace cosmographer {

Fuzz::Fuzz(
        GlimmerSoul *glimmerSoul,
        PainterCommunity *painterCommunity
) :
        glimmerSoul{glimmerSoul},
        painterCommunity{painterCommunity} {

}

void Fuzz::live() {
    if (glimmerSoul->age == 0) {
        auto granularity = SIZE_AXIOM * 15;
        for (int i = 0; i < granularity; i++) {
            painterCommunity->painter->advance(1 + randomizer->generate(10) * CHAOS_AXIOM, glimmerSoul->color);
            painterCommunity->painter->rotate(2 * M_PI / granularity);
        }
    }
}

}
