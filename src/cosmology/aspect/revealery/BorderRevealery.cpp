#include "BorderRevealery.h"
#include "cosmology/aspect/glimmering/glimmer/lively/LumionMimic.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerMakers.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Canvas.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/DragonCurve.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/Curve.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Drift.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Lifespan.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Fade.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/WorkshopCurve.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Mutator.h"
#include "cosmology/aspect/glimmering/glimmer/lively/LumionMimic.h"

namespace cosmographer {

void BorderRevealery::reveal(
        Lumion *lumion
) {
    int glimmerCount = COUNT_AXIOM * CONSTANTS->maxGlimmerSpawnCount * lumion->magnitude;
    if (glimmerCount < 1) {
        glimmerCount = 1;
    }
    for (int count = 0; count < glimmerCount; count++) {
        auto color = CLOISTER->chromatica->getColor();
        color.lightness = 90 - 50 * lumion->magnitude;
        auto glimmerSoul = mkup<GlimmerSoul>(
                lumion,
                lumion->latticePoint,
                color,
                lumion->magnitude
        );
        auto glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));
        glimmer->addLively(mkup<LumionMimic>(glimmer->glimmerSoul));

        glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));

        float inclinationOffset = cast(float, count) / glimmerCount;
        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));
        glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));

        community->glimmering->addGlimmer(mv(glimmer));

        glimmerSoul = mkup<GlimmerSoul>(
                lumion,
                lumion->latticePoint,
                CONSTANTS->latticeInitialColor,
                lumion->magnitude
        );
        glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));

        glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));

        inclinationOffset = cast(float, count) / glimmerCount;
        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));
        glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
