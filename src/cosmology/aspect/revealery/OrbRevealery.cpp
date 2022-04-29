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
#include "cosmology/aspect/glimmering/glimmer/lively/Mutator.h"
#include "cosmology/aspect/glimmering/glimmer/lively/LumionMimic.h"

namespace cosmographer {

OrbRevealery::OrbRevealery(

) :
        currentShape{0},
        currentInclination{0},
        previousEnergy{0} {

}

void OrbRevealery::experienceSignal() {
    auto &signal = CLOISTER->signalarium->stft;
    currentInclination += signal.energy - previousEnergy;
    if (currentInclination > 10) {
        currentInclination = 0;
    } else if (currentInclination < -10) {
        currentInclination = 0;
    }
    if (signal.energy * 2 > previousEnergy) {
        currentShape = RANDOM.generate(4);
    }
    previousEnergy = signal.energy;
}

void OrbRevealery::reveal(
        Lumion *lumion
) {
    auto glimmerCount = 20 * lumion->magnitude;
    if (glimmerCount < 3) {
        glimmerCount = 3;
    }
    for (int count = 0; count < glimmerCount; count++) {
        auto color = lumion->color;
        color.lightness = 90 - 50 * lumion->magnitude;
        auto glimmerSoul = mkup<GlimmerSoul>(
                lumion,
                lumion->latticePoint,
                color,
                lumion->magnitude
        );
        auto glimmer = mkup<Glimmer>(community->glimmering->fetchSubcommunity(), mv(glimmerSoul));
        glimmer->addLively(mkup<LumionMimic>(glimmer->glimmerSoul));

        auto mode = paradigm->microMode;
        if (mode == 0) {
            if (currentShape == 0) {
                glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerSoul));
            } else if (currentShape == 1) {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
                glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerSoul, painterCommunity, orientation));
            } else if (currentShape == 2) {
                auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
                auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
                auto spin = 2 * M_PI * CLOISTER->randomizer->generateProportion();
                glimmer->addLively(mkup<Curve>(glimmer->glimmerSoul, painterCommunity, orientation, spin));
            } else if (currentShape == 3) {
                glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 0.2));
                glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 0.4));
                glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 0.8));
            }
        } else if (mode == 1) {
            glimmer->addIlluminable(mkup<Circle>(glimmer->glimmerSoul));
        } else {
            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            glimmer->addLively(mkup<DragonCurve>(glimmer->glimmerSoul, painterCommunity, orientation));
        }
//        else if (mode == 3) {
//            auto painterCommunity = GlimmerMakers::createPainterCommunity(glimmer.get());
//            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
//            auto spin = 2 * M_PI * CLOISTER->randomizer->generateProportion();
//            glimmer->addLively(mkup<Curve>(glimmer->glimmerSoul, painterCommunity, orientation, spin));
//        } else if (mode == 4) {
//            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 0.2));
//            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 0.4));
//            glimmer->addIlluminable(mkup<Rectangle>(glimmer->glimmerSoul, 0.8));
//        }

        float inclinationOffset = cast(float, count) / glimmerCount * 2 * M_PI;
        glimmer->addLively(mkup<Mutator>(glimmer->glimmerSoul));
        glimmer->addLively(mkup<Drift>(glimmer->glimmerSoul, inclinationOffset));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
