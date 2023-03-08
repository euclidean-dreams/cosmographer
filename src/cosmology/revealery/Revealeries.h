#pragma once

#include "Revealery.h"
#include "cosmology/glimmering/glimmer/lively/LumionMimic.h"
#include "cosmology/glimmering/glimmer/lively/Mutator.h"
#include "cosmology/glimmering/glimmer/lively/Drift.h"
#include "cosmology/glimmering/glimmer/GlimmerMakers.h"
#include "cosmology/glimmering/glimmer/lindogram/Wander.h"
#include "cosmology/glimmering/glimmer/lindogram/Fuzz.h"
#include "cosmology/glimmering/glimmer/lindogram/Odds.h"
#include "cosmology/glimmering/glimmer/lindogram/DragonCurve.h"
#include "cosmology/glimmering/glimmer/illuminable/Illuminables.h"
#include "cosmology/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/glimmering/glimmer/lindogram/Triangle.h"
#include "cosmology/glimmering/glimmer/lively/Fade.h"

namespace PROJECT_NAMESPACE {

class SpectrumRevealery : public Revealery {
public:
    void reveal(
            Lumion *lumion
    ) override {
        int glimmerCount = MAGNITUDE_AXIOM * constants->glimmerSpawnCountScaler * lumion->magnitude / 100;
        if (glimmerCount < 1) {
            glimmerCount = 1;
        }
        for (int count = 0; count < glimmerCount; count++) {
            auto glimmerSoul = mkup<GlimmerSoul>(
                    lumion,
                    Point{lumion->latticePoint.x, lumion->latticePoint.y},
                    chromatica->getColor(),
                    lumion->magnitude
            );
            auto glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));

            // illuminables
            float inclinationOffset = pole->pole + cast(float, count) / glimmerCount * M_PI / 2 - M_PI / 4;
            if (microMode == 0) {
                glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerSoul));
            } else if (microMode == 1) {
                glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));
            } else if (microMode == 2) {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerSoul, painterCommunity, 0));
            } else {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                glimmer->addLively(mkup<Triangle>(glimmer->glimmerSoul, painterCommunity, inclinationOffset));
            }
            glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));
            glimmer->addLively(mkup<Fade>(glimmer->glimmerSoul));
            glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));

            community->glimmering->addGlimmer(mv(glimmer));
        }
    }
};

class OddRevealery : public Revealery {
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

        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, pole->pole));
        glimmer->addLively(mkup<Fade>(glimmer->glimmerSoul));
        glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));

        community->glimmering->addGlimmer(mv(glimmer));
    }
};

class RandomRevealery : public Revealery {
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

        auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
        auto glimmerType = randomizer->generate(6);
        if (glimmerType == 0) {
            glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerSoul));
        } else if (glimmerType == 1) {
            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 1));
        }
//        } else if (glimmerType == 2) {
//            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
//            glimmer->addLively(mkup<Triangle>(glimmer->glimmerSoul, painterCommunity, 0));
//        } else if (glimmerType == 3) {
//            glimmer->addLively(mkup<Orbit>(glimmer->glimmerSoul, painterCommunity));
//        } else if (glimmerType == 4) {
//            glimmer->addLively(mkup<Wiggle>(glimmer->glimmerSoul, painterCommunity));
//        } else if (glimmerType == 5) {
//            glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerSoul, painterCommunity, 0));
//        } else {
//            glimmer->addLively(mkup<Wonk>(glimmer->glimmerSoul, painterCommunity));
//        }
        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, pole->pole));
        glimmer->addLively(mkup<Fade>(glimmer->glimmerSoul));
        glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));

        community->glimmering->addGlimmer(mv(glimmer));
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
