#include "DragonCurve.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/lindogram/Painter.h"
#include "DragonCurveSystem.h"

namespace cosmographer {

DragonCurve::DragonCurve(
        Paradigm *paradigm,
        float orientation
) :
        Liaison<LindogramCommunity>(paradigm),
        lastRuneIndex{0} {
    subCommunity.canvas = mkup<Canvas>();
    subCommunity.canvas->initialize(&subCommunity);
    subCommunity.painter = mkup<Painter>();
    subCommunity.painter->initialize(&subCommunity);
    subCommunity.painter->rotate(orientation);
}

void DragonCurve::illuminate(Lattice &lattice) {
    auto endRuneIndex = community->size * community->age;
    for (int runeIndex = lastRuneIndex; runeIndex < endRuneIndex && runeIndex < dragonCurveRunes.size(); runeIndex++) {
        auto rune = dragonCurveRunes[runeIndex];
        if (rune == DragonCurveRunology::advance) {
            subCommunity.painter->advance(1, community->color);
        } else if (rune == DragonCurveRunology::rotateLeftQuarter) {
            subCommunity.painter->rotate(M_PI / 2);
        } else if (rune == DragonCurveRunology::rotateRightQuarter) {
            subCommunity.painter->rotate(-M_PI / 2);
        }
    }
    lastRuneIndex = endRuneIndex;
    subCommunity.canvas->show(lattice, community->locus);
}

}
