#include "WorkshopRevealery.h"
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

namespace cosmographer {

void WorkshopRevealery::reveal(LumionExcitation excitation) {
    int glimmerCount = GLIMMER_COUNT_AXIOM * CONSTANTS->maxGlimmerSpawnCount * excitation.magnitude;
    if (glimmerCount < 1) {
        glimmerCount = 1;
    }
    for (int count = 0; count < glimmerCount; count++) {
        auto locus = excitation.point;
        auto color = CLOISTER->chromatica->getColor();
        color.lightness = 90 - 50 * excitation.magnitude;
        auto size = excitation.magnitude * 25 * GLIMMER_SIZE_AXIOM + 2;
        auto glimmer = mkup<Glimmer>(
                community->glimmering->fetchSubcommunity(),
                locus,
                color,
                size
        );


        // illuminables
//        auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
//        auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
//        glimmer->addLively(mkup<WorkshopCurve>(glimmer->glimmerSoul, painterCommunity, orientation));

        glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));

        auto lifespanWrapper = mkup<Lifespan>(glimmer->glimmerSoul);
        auto fadeColor = CONSTANTS->latticeInitialColor;
        fadeColor.hue = HSL_HUE_MAX * WORKSHOP_AXIOM;
        glimmer->addLively(mkup<Fade>(glimmer->glimmerSoul, lifespanWrapper.get(), fadeColor));
        glimmer->addLively(mv(lifespanWrapper));

        float inclinationOffset = cast(float, count) / glimmerCount;
        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
