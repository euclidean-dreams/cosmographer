#include "WorkshopRevealery.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/painter/Canvas.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/DragonCurve.h"
#include "cosmology/aspect/glimmering/glimmer/lindogram/RandomWalk.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Drift.h"
#include "cosmology/aspect/glimmering/glimmer/lively/Fade.h"
#include "cosmology/aspect/glimmering/glimmer/terminable/FullyFaded.h"
#include "cosmology/aspect/glimmering/glimmer/terminable/OriginOffLattice.h"
#include "cosmology/aspect/glimmering/glimmer/terminable/Age.h"
#include "cosmology/aspect/glimmering/glimmer/lively/AgeIncrementer.h"

namespace cosmographer {

WorkshopRevealery::WorkshopRevealery(

) :
        energyAverage{50} {

}

void WorkshopRevealery::reveal(LumionExcitation excitation) {
    energyAverage.addSample(excitation.energy);
    auto energyDelta = excitation.energy / energyAverage.calculate();

//    auto ephemera = mkup<Linger>(lighten);
    int glimmerCount = GLIMMER_COUNT_AXIOM * CONSTANTS->maxGlimmerSpawnCount * excitation.magnitude;
    if (glimmerCount < 1) {
        glimmerCount = 1;
    }
    for (int count = 0; count < glimmerCount; count++) {
        auto glimmer = mkup<Glimmer>();
        auto glimmerCommunityController = mkup<GlimmerCommunity>(community->paradigm);
        auto glimmerCommunity = glimmerCommunityController.get();
        glimmer->constituents.push_back(mv(glimmerCommunityController));

        // color
        glimmerCommunity->age = 0;
        glimmerCommunity->color = CLOISTER->chromatica->getColor();
        glimmerCommunity->color.lightness = 70 - 50 * excitation.magnitude;

        // locus
        if (PARADIGM->mode == RADIATE_MODE || PARADIGM->mode == WORKSHOP_MODE) {
            glimmerCommunity->locus = Point{cast(double, CONSTANTS->latticeWidth / 2),
                                            cast(double, CONSTANTS->latticeHeight / 2)};
        } else {
            glimmerCommunity->locus = excitation.point;
        }

        // illuminables
        if (PARADIGM->mode == CIRCLE_MODE) {
            glimmerCommunity->size = excitation.magnitude * 25 * GLIMMER_SIZE_AXIOM + 2;
            auto illuminableController = mkup<Circle>(glimmerCommunity);
            glimmer->illuminables.push_back(illuminableController.get());
            glimmer->constituents.push_back(mv(illuminableController));
        } else if (PARADIGM->mode == RECTANGLE_MODE) {
            glimmerCommunity->size = excitation.magnitude * 50 * GLIMMER_SIZE_AXIOM + 2;
            auto illuminableController = mkup<Rectangle>(glimmerCommunity, 1);
            glimmer->illuminables.push_back(illuminableController.get());
            glimmer->constituents.push_back(mv(illuminableController));
        } else if (PARADIGM->mode == DRAGON_MODE || PARADIGM->mode == RADIATE_MODE) {
            // painter community
            auto painterCommunityController = mkup<PainterCommunity>(community->paradigm);
            auto painterCommunity = painterCommunityController.get();
            glimmer->constituents.push_back(mv(painterCommunityController));

            auto painterController = mkup<Painter>(painterCommunity);
            painterCommunity->painter = painterController.get();
            glimmer->constituents.push_back(mv(painterController));

            auto canvasController = mkup<Canvas>(glimmerCommunity);
            painterCommunity->canvas = canvasController.get();
            glimmer->constituents.push_back(mv(canvasController));
            glimmer->illuminables.push_back(painterCommunity->canvas);

            // dragon curve
            glimmerCommunity->size = excitation.magnitude * 50 * GLIMMER_SIZE_AXIOM + 2;
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            auto dragonCurveController = mkup<DragonCurve>(glimmerCommunity, painterCommunity, orientation);
            glimmer->livelies.push_back(dragonCurveController.get());
            glimmer->constituents.push_back(mv(dragonCurveController));
        } else {
            // painter community
            auto painterCommunityController = mkup<PainterCommunity>(community->paradigm);
            auto painterCommunity = painterCommunityController.get();
            glimmer->constituents.push_back(mv(painterCommunityController));

            auto painterController = mkup<Painter>(painterCommunity);
            painterCommunity->painter = painterController.get();
            glimmer->constituents.push_back(mv(painterController));

            auto canvasController = mkup<Canvas>(glimmerCommunity);
            painterCommunity->canvas = canvasController.get();
            glimmer->constituents.push_back(mv(canvasController));
            glimmer->illuminables.push_back(painterCommunity->canvas);

            // random walk
            glimmerCommunity->size = excitation.magnitude * 50 * GLIMMER_SIZE_AXIOM + 2;
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            auto spin = 2 * M_PI * CLOISTER->randomizer->generateProportion() * excitation.magnitude;
            auto randomWalkController = mkup<RandomWalk>(glimmerCommunity, painterCommunity, orientation, spin);
            glimmer->livelies.push_back(randomWalkController.get());
            glimmer->constituents.push_back(mv(randomWalkController));
        }
        // age incrementer
        auto ageIncrementerController = mkup<AgeIncrementer>(glimmerCommunity);
        glimmer->livelies.push_back(ageIncrementerController.get());
        glimmer->constituents.push_back(mv(ageIncrementerController));

        // drift
        float inclinationOffset = cast(float, count) / glimmerCount;
        auto driftController = mkup<Drift>(glimmerCommunity, inclinationOffset);
        glimmer->livelies.push_back(driftController.get());
        glimmer->constituents.push_back(mv(driftController));

        // fade
        auto lifespan = 300 * EPHEMERA_AXIOM_2;
        if (lifespan < 5) {
            lifespan = 5;
        }
        auto finalColor = CONSTANTS->latticeInitialColor;
        finalColor.hue = glimmerCommunity->color.hue;
        auto fadeController = mkup<Fade>(glimmerCommunity, glimmerCommunity->color, finalColor, lifespan);
        glimmer->livelies.push_back(fadeController.get());
        glimmer->constituents.push_back(mv(fadeController));

        // fully faded
        auto fullyFadedController = mkup<FullyFaded>(glimmerCommunity);
        glimmer->terminbles.push_back(fullyFadedController.get());
        glimmer->constituents.push_back(mv(fullyFadedController));

        // origin off lattice
        auto originOffLatticeController = mkup<OriginOffLattice>(glimmerCommunity);
        glimmer->terminbles.push_back(originOffLatticeController.get());
        glimmer->constituents.push_back(mv(originOffLatticeController));

        // age
        auto ageController = mkup<Age>(glimmerCommunity, lifespan);
        glimmer->terminbles.push_back(ageController.get());
        glimmer->constituents.push_back(mv(ageController));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
