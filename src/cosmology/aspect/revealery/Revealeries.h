#pragma once

#include "Revealery.h"
#include "cosmology/aspect/glimmering/glimmer/lively/LumionMimic.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Mutator.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Drift.h"
#include "cosmology/aspect/glimmering/glimmer/GlimmerMakers.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/Wander.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/Fuzz.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/Odds.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/DragonCurve.h"

namespace PROJECT_NAMESPACE {

class OddRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override {
        auto glimmerSoul = mkup<GlimmerSoul>(
                lumion,
                Point{lumion->latticePoint.x, lumion->latticePoint.y},
                lumion->color,
                lumion->magnitude
        );
        auto glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));
        glimmer->addLively(mkup<LumionMimic>(glimmer->glimmerSoul));

        auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
        if (microMode == 0) {
            glimmer->addLively(mkup<Orbit>(glimmer->glimmerSoul, painterCommunity));
        } else if (microMode == 1) {
            glimmer->addLively(mkup<Wiggle>(glimmer->glimmerSoul, painterCommunity));
        } else if (microMode == 2) {
            glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerSoul, painterCommunity, 0));
        } else {
            glimmer->addLively(mkup<Wonk>(glimmer->glimmerSoul, painterCommunity));
        }
        glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));
        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, 0));

        community->glimmering->addGlimmer(mv(glimmer));
    }
};

}
