#include "SpectrumRevealery.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerMakers.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Canvas.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/DragonCurve.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/Wander.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Drift.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Lifespan.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Fade.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Mutator.h"
#include "cosmology/aspect/glimmering/glimmer/lively/LumionMimic.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/Ring.h"

namespace cosmographer {

void SpectrumRevealery::reveal(
        Lumion *lumion
) {
    int glimmerCount = COUNT_AXIOM * constants->glimmerSpawnCountScaler * lumion->magnitude / 1000;
    if (glimmerCount < 1) {
        glimmerCount = 1;
    }
    for (int count = 0; count < glimmerCount; count++) {
        auto glimmerSoul = mkup<GlimmerSoul>(
                lumion,
                Point{lumion->latticePoint.x, lumion->latticePoint.y},
                lumion->color,
                lumion->magnitude
        );
        auto glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));
        glimmer->addLively(mkup<LumionMimic>(glimmer->glimmerSoul));


        // illuminables
        if (microMode == 0) {
            glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerSoul));
        } else if (microMode == 1) {
            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));
        } else if (microMode == 2) {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            auto orientation = 2 * M_PI * randomizer->generateProportion();
            glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerSoul, painterCommunity, orientation));
        } else if (microMode == 3) {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            glimmer->addLively(mkup<Wander>(glimmer->glimmerSoul, painterCommunity));
        } else {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            glimmer->addLively(mkup<Ring>(glimmer->glimmerSoul, painterCommunity));
        }
        glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));

        float inclinationOffset = cast(float, count) / glimmerCount * 2 * M_PI;
        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
