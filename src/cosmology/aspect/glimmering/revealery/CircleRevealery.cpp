#include "CircleRevealery.h"
#include "cosmology/aspect/glimmering/glimmer/Glimmer.h"
#include "cosmology/aspect/glimmering/glimmer/ephemera/Linger.h"
#include "cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.h"
#include "cosmology/aspect/glimmering/glimmer/ephemera/Drift.h"

namespace cosmographer {

void CircleRevealery::reveal(LumionExcitation excitation) {
    auto lighten = true;

    // color
    auto color = CLOISTER->chromatica->getColor();
    if (lighten) {
        color.lightness = 100 - 60 * excitation.magnitude;
    } else {
        color.lightness = excitation.magnitude * 60;
    }
    auto radius = excitation.magnitude * 25 * GLIMMER_SIZE_AXIOM + 2;

//    auto ephemera = mkup<Linger>(lighten);
    int glimmerCount = GLIMMER_COUNT_AXIOM * MAX_GLIMMER_COUNT * excitation.magnitude;
    if(glimmerCount < 1) {
        glimmerCount = 1;
    }
    for (int count = 0; count < glimmerCount; count++) {
        float inclinationOffset = cast(float, count) / glimmerCount;
        auto ephemera = mkup<Drift>(inclinationOffset);
        auto illuminable = mkup<Circle>(radius);
        auto glimmer = mkup<Glimmer>(
                community,
                mv(ephemera),
                mv(illuminable),
                excitation.point,
                color
        );
        glimmer->initialize(community);
        community->glimmers.push_back(mv(glimmer));
    }
}

}
