#include "Fuzz.h"
#include "cosmology/glimmering/glimmer/illuminable/painter/Painter.h"

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
        auto granularity = MAGNITUDE_AXIOM * 15;
        for (int i = 0; i < granularity; i++) {
            painterCommunity->painter->advance(1 + randomizer->generate(25) * MAGNITUDE_AXIOM, glimmerSoul->color);
            painterCommunity->painter->rotate(2 * M_PI / granularity);
        }
    }
}

}
