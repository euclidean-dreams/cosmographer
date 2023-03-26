#include "DragonCurve.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/Painter.h"
#include "DragonCurveSystem.h"
#include "cosmology/revealeryaspect/mesh/lumion/Lumion.h"

namespace cosmographer {

DragonCurve::DragonCurve(
        GlimmerSoul *glimmerSoul,
        PainterCommunity *painterCommunity,
        float initialOrientation
) :
        glimmerSoul{glimmerSoul},
        painterCommunity{painterCommunity},
        initialOrientation{initialOrientation},
        lastRuneIndex{0} {
}

void DragonCurve::live() {
    if (glimmerSoul->age == 0) {
        painterCommunity->painter->rotate(initialOrientation);
    }
    auto endRuneIndex = 4 * glimmerSoul->lumion->magnitude * MAGNITUDE_AXIOM;
    for (int runeIndex = lastRuneIndex;
         runeIndex < endRuneIndex && runeIndex < dragonCurveRunes.size(); runeIndex++) {
        auto rune = dragonCurveRunes[runeIndex];
        if (rune == DragonCurveRunology::advance) {
            painterCommunity->painter->advance(1, glimmerSoul->color);
        } else if (rune == DragonCurveRunology::rotateLeftQuarter) {
            painterCommunity->painter->rotate(M_PI / 2);
        } else if (rune == DragonCurveRunology::rotateRightQuarter) {
            painterCommunity->painter->rotate(-M_PI / 2);
        }
    }
    lastRuneIndex = endRuneIndex;
}

}
