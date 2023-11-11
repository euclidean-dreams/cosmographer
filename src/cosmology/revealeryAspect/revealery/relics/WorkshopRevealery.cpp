#include "WorkshopRevealery.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/GlimmerMakers.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/painter/Painter.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/painter/Canvas.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lindogram/DragonCurve.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lindogram/Wander.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lively/Drift.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lively/Lifespan.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lively/Fade.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lindogram/WorkshopCurve.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lively/Mutator.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lively/LumionMimic.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lindogram/Triangle.h"

namespace cosmographer {

void WorkshopRevealery::reveal(
        Lumion *lumion
) {
    auto glimmerSoul = mkup<GlimmerSoul>(
            lumion,
            Point{lumion->latticePoint.x, lumion->latticePoint.y},
            lumion->color,
            lumion->magnitude
    );
    auto glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));
    glimmer->addLively(mkup<LumionMimic>(glimmer->glimmerSoul));

    glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));

    float inclinationOffset = 2 * M_PI;
    glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));
    community->glimmering->addGlimmer(mv(glimmer));
}

}
