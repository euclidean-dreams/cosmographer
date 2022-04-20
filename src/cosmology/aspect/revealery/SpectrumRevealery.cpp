#include "SpectrumRevealery.h"
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

namespace cosmographer {

void SpectrumRevealery::reveal(LumionExcitation excitation) {
    int glimmerCount = COUNT_AXIOM * CONSTANTS->maxGlimmerSpawnCount * excitation.magnitude;
    if (glimmerCount < 1) {
        glimmerCount = 1;
    }
    for (int count = 0; count < glimmerCount; count++) {
        auto locus = excitation.point;
        auto color = CLOISTER->chromatica->getColor();
        color.lightness = 90 - 50 * excitation.magnitude;
        auto glimmer = mkup<Glimmer>(
                community->glimmering->fetchSubcommunity(),
                locus,
                color,
                calculateBaseSize(excitation.magnitude)
        );


        // illuminables
        if (paradigm->microMode == 0) {
            glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerSoul));
        } else if (paradigm->microMode == 1) {
            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));
        } else if (paradigm->microMode == 2) {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerSoul, painterCommunity, orientation));
        } else {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            auto spin = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            glimmer->addLively(mkup<Curve>(glimmer->glimmerSoul, painterCommunity, orientation, spin));
        }
        auto lifespanWrapper = mkup<Lifespan>(glimmer->glimmerSoul);
        glimmer->addLively(mkup<Fade>(glimmer->glimmerSoul, lifespanWrapper.get(), HSLColor{color.hue, 0, 100}));
        glimmer->addLively(mv(lifespanWrapper));

        float inclinationOffset = cast(float, count) / glimmerCount;
        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
