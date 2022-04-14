#include "DragonCurve.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"
#include "DragonCurveSystem.h"

namespace cosmographer {

DragonCurve::DragonCurve(
        GlimmerCommunity *glimmerCommunity,
        PainterCommunity *painterCommunity,
        float initialOrientation
) :
        glimmerCommunity{glimmerCommunity},
        painterCommunity{painterCommunity},
        initialOrientation{initialOrientation},
        lastRuneIndex{0} {
}

void DragonCurve::live() {
    if (lastRuneIndex == 0) {
        painterCommunity->painter->rotate(initialOrientation);
    }
    auto endRuneIndex = glimmerCommunity->size * glimmerCommunity->age;
    for (int runeIndex = lastRuneIndex; runeIndex < endRuneIndex && runeIndex < dragonCurveRunes.size(); runeIndex++) {
        auto rune = dragonCurveRunes[runeIndex];
        if (rune == DragonCurveRunology::advance) {
            painterCommunity->painter->advance(1, glimmerCommunity->color);
        } else if (rune == DragonCurveRunology::rotateLeftQuarter) {
            painterCommunity->painter->rotate(M_PI / 2);
        } else if (rune == DragonCurveRunology::rotateRightQuarter) {
            painterCommunity->painter->rotate(-M_PI / 2);
        }
    }
    lastRuneIndex = endRuneIndex;
}

}
