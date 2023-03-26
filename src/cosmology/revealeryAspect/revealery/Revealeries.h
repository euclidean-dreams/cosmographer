#pragma once

#include "Revealery.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lively/LumionMimic.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lively/Mutator.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lively/Drift.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/GlimmerMakers.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lindogram/Wander.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lindogram/Fuzz.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lindogram/Odds.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lindogram/DragonCurve.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/Illuminables.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lindogram/Triangle.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/lively/Fade.h"

namespace PROJECT_NAMESPACE {

class SpectrumRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override {
        int glimmerCount = 1;
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

            // illuminables
            float inclinationOffset = randomizer->generateProportion() * 2 * M_PI;
            if (microMode == 1) {
                glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));
            } else if (microMode == 2) {
                glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerSoul));
            } else if (microMode == 3) {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                glimmer->addLively(mkup<Triangle>(glimmer->glimmerSoul, painterCommunity, inclinationOffset));
            }  else if (microMode == 4) {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerSoul, painterCommunity, 0));
            } else if (microMode == 5) {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                glimmer->addLively(mkup<Wiggle>(glimmer->glimmerSoul, painterCommunity));
            } else if (microMode == 6) {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                glimmer->addLively(mkup<Orbit>(glimmer->glimmerSoul, painterCommunity));
            } else {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                glimmer->addLively(mkup<Wonk>(glimmer->glimmerSoul, painterCommunity));
            }

            glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));
            glimmer->addLively(mkup<Fade>(glimmer->glimmerSoul));
//            glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));

            community->glimmering->addGlimmer(mv(glimmer));
        }
    }
};

class LanternRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override {
        auto glimmerSoul = mkup<GlimmerSoul>(
                lumion,
                Point{lumion->latticePoint.x, lumion->latticePoint.y},
                chromatica->getColor(),
                lumion->magnitude
        );
        auto glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));
        glimmer->addLively(mkup<LumionMimic>(glimmer->glimmerSoul));

        glimmer->addIlluminable(mkup<Dot>(glimmer->glimmerSoul));

        glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));
        community->glimmering->addGlimmer(mv(glimmer));
    }
};

}
