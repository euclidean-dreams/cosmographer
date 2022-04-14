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
        if (PARADIGM->microMode == 0) {
            glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerCommunity));
        } else if (PARADIGM->microMode == 1) {
            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerCommunity, 1));
        } else if (PARADIGM->microMode == 2) {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerCommunity, painterCommunity, orientation));
        } else {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            auto spin = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            glimmer->addLively(mkup<Curve>(glimmer->glimmerCommunity, painterCommunity, orientation, spin));
        }
        glimmer->addLively(mkup<Lifespan>(glimmer->glimmerCommunity));

        float inclinationOffset = cast(float, count) / glimmerCount;
        glimmer->addLively(mkup<Drift>(glimmer->glimmerCommunity, inclinationOffset));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
