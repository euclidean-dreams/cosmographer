#include "OrbRevealery.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Canvas.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/DragonCurve.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/Curve.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Drift.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Fade.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerMakers.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Lifespan.h"

namespace cosmographer {

void OrbRevealery::reveal(LumionExcitation excitation) {
    auto glimmerCount = 20 * excitation.magnitude;
    if (glimmerCount < 3) {
        glimmerCount = 3;
    }
    for (int count = 0; count < glimmerCount; count++) {
        auto locus = Point{cast(float, CONSTANTS->latticeWidth / 2),
                           cast(float, CONSTANTS->latticeHeight / 2)};
        auto color = CLOISTER->chromatica->getColor();
        color.lightness = 90 - 50 * excitation.magnitude;
        auto size = excitation.magnitude * 50 * GLIMMER_SIZE_AXIOM + 2;
        auto glimmer = mkup<Glimmer>(
                community->glimmering->fetchSubcommunity(),
                locus,
                color,
                size
        );
        glimmer->addLively(mkup<Lifespan>(glimmer->glimmerCommunity));

        auto mode = community->paradigm->microMode;
        if (mode == 0) {
            glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerCommunity));
        } else if (mode == 1) {
            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerCommunity, excitation.magnitude * 5));
        } else if (mode == 2) {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerCommunity, painterCommunity, orientation));
        } else if (mode == 3) {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            auto spin = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            glimmer->addLively(mkup<Curve>(glimmer->glimmerCommunity, painterCommunity, orientation, spin));
        } else if (mode == 4) {
            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerCommunity, 0.2));
            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerCommunity, 0.4));
            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerCommunity, 0.8));
        }

        float inclinationOffset = cast(float, count) / glimmerCount;
        glimmer->addLively(mkup<Drift>(glimmer->glimmerCommunity, inclinationOffset));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
