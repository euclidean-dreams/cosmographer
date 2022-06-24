#include "PromenadeRevealery.h"
#include "cosmology/aspect/glimmering/glimmer/lively/LumionMimic.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Mutator.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Fade.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Drift.h"

using namespace cosmographer;

void PromenadeRevealery::reveal(cosmographer::Lumion *lumion) {
    auto glimmerSoul = mkup<GlimmerSoul>(
            lumion,
            Point{lumion->latticePoint.x, lumion->latticePoint.y},
            lumion->color,
            lumion->magnitude
    );
    auto glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));

    glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));

    glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, 0));
    glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));
    community->glimmering->addGlimmer(mv(glimmer));
}
