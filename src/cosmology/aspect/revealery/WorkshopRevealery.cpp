#include "WorkshopRevealery.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/glimmering/glimmer/ephemera/Fade.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/aspect/glimmering/glimmer/ephemera/Drift.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/parametro/Paraboloid.h"
#include "cosmology/aspect/glimmering/glimmer/terminus/FullyFaded.h"
#include "cosmology/aspect/glimmering/glimmer/terminus/OriginOffLattice.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.h"
#include "cosmology/aspect/glimmering/glimmer/ephemera/Grow.h"
#include "cosmology/aspect/glimmering/glimmer/terminus/Age.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/lindogram/DragonCurve.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/lindogram/Painter.h"

namespace cosmographer {

WorkshopRevealery::WorkshopRevealery(

) :
        energyAverage{50} {

}

void WorkshopRevealery::reveal(LumionExcitation excitation) {
    energyAverage.addSample(excitation.energy);
    auto energyDelta = excitation.energy / energyAverage.calculate();
    // color
    auto color = CLOISTER->chromatica->getColor();
    color.lightness = 70 - 50 * excitation.magnitude;
//    color.lightness = 20 + 70 * excitation.magnitude;

//    auto ephemera = mkup<Linger>(lighten);
    int glimmerCount = GLIMMER_COUNT_AXIOM * CONSTANTS->maxGlimmerSpawnCount * excitation.magnitude;
    if (glimmerCount < 1) {
        glimmerCount = 1;
    }
    for (int count = 0; count < glimmerCount; count++) {
        // locus

        Point locus;
        if (PARADIGM->mode == RADIATE_MODE) {
            locus = Point{cast(double, CONSTANTS->latticeWidth / 2), cast(double, CONSTANTS->latticeHeight / 2)};
        } else {
            locus = excitation.point;
        }

        // illuminable
        up<Illuminable> illuminable;
        float size;
        size = excitation.magnitude * energyDelta * GLIMMER_SIZE_AXIOM * 500 + 2;

        if (PARADIGM->mode == CIRCLE_MODE) {
            size = excitation.magnitude * 25 * GLIMMER_SIZE_AXIOM + 2;
            illuminable = mkup<Circle>();
        } else if (PARADIGM->mode == RECTANGLE_MODE) {
            size = excitation.magnitude * 50 * GLIMMER_SIZE_AXIOM + 2;
            illuminable = mkup<Rectangle>(2 * excitation.magnitude);
        } else if (PARADIGM->mode == DRAGON_MODE || PARADIGM->mode == RADIATE_MODE) {
            size = excitation.magnitude * 50 * GLIMMER_SIZE_AXIOM + 2;
            auto orientation = 2 * M_PI * CLOISTER->randomizer->generateProportion();
            illuminable = mkup<DragonCurve>(community->paradigm, orientation);
        } else {
            size = 2;
            illuminable = mkup<Rectangle>(1);
        }

        // wiring
        auto glimmer = mkup<Glimmer>(
                PARADIGM,
                mv(illuminable),
                locus,
                color,
                size
        );

        // ephemera
        float inclinationOffset = cast(float, count) / glimmerCount;
        glimmer->addEphemera(mkup<Drift>(inclinationOffset));

        auto lifespan = 300 * EPHEMERA_AXIOM_2;
        if (lifespan < 5) {
            lifespan = 5;
        }
        auto finalColor = CONSTANTS->latticeInitialColor;
        finalColor.hue = color.hue;
        glimmer->addEphemera(mkup<Fade>(color, finalColor, lifespan));

//        glimmer->addEphemera(mkup<Grow>());

        // terminus
        glimmer->addTerminus(mkup<FullyFaded>());
        glimmer->addTerminus(mkup<OriginOffLattice>());
        glimmer->addTerminus(mkup<Age>(lifespan));

        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
