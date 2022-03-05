#include "BrushPartyRevealery.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/glimmering/glimmer/ephemera/Linger.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/aspect/glimmering/glimmer/ephemera/Drift.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/parametro/Paraboloid.h"

namespace cosmographer {

void BrushPartyRevealery::reveal(LumionExcitation excitation) {
    auto lighten = true;

    // color
    auto color = CLOISTER->chromatica->getColor();
    if (lighten) {
        color.lightness = 100 - 60 * excitation.magnitude;
    } else {
        color.lightness = excitation.magnitude * 60;
    }

//    auto ephemera = mkup<Linger>(lighten);
    int glimmerCount = GLIMMER_COUNT_AXIOM * MAX_GLIMMER_COUNT * excitation.magnitude;
    if (glimmerCount < 1) {
        glimmerCount = 1;
    }
    for (int count = 0; count < glimmerCount; count++) {

        // ephemera
        up<Ephemera> ephemera;

        float inclinationOffset = cast(float, count) / glimmerCount;
        ephemera = mkup<Drift>(inclinationOffset);

//        ephemera = mkup<Linger>(lighten);

        // locus
        auto locus = excitation.point;
//        auto locus = Point{cast(double, PARADIGM->latticeWidth / 2), cast(double, PARADIGM->latticeHeight / 2)};

        // illuminable
        up<Illuminable> illuminable;
        float size;

        size = excitation.magnitude * 25 * GLIMMER_SIZE_AXIOM + 2;
        illuminable = mkup<Circle>();

//        size = excitation.magnitude * 25 * GLIMMER_SIZE_AXIOM + 2;
//        illuminable = mkup<Paraboloid>(1.5);

        // wiring
        auto glimmer = mkup<Glimmer>(
                PARADIGM,
                mv(ephemera),
                mv(illuminable),
                locus,
                color,
                size
        );
        community->glimmering->addGlimmer(mv(glimmer));
    }
}

}
