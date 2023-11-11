#pragma once

#include "Default.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/lively/Lively.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/GlimmerSoul.h"
#include "cosmology/revealeryAspect/glimmering/glimmer/illuminable/painter/Painter.h"

namespace PROJECT_NAMESPACE {

class Orbit : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;

    Orbit(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity
    ) :
            glimmerSoul{glimmerSoul},
            painterCommunity{painterCommunity} {
    }

    void live() {
        if (glimmerSoul->age == 0) {
            painterCommunity->painter->rotate(2 * M_PI * randomizer->generateProportion());
        }
        for (int i = 0; i < MAGNITUDE_AXIOM * 2; i++) {
            painterCommunity->painter->advance(1, glimmerSoul->color);
            painterCommunity->painter->rotate(M_PI / 16 * randomizer->generateProportion());
        }
    }
};

class Wiggle : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;
    bool directionSwitch = false;

    Wiggle(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity
    ) :
            glimmerSoul{glimmerSoul},
            painterCommunity{painterCommunity} {
    }

    void live() {
        if (glimmerSoul->age == 0) {
            painterCommunity->painter->rotate(2 * M_PI * randomizer->generateProportion());
        }
        for (int i = 0; i < MAGNITUDE_AXIOM * 2; i++) {
            painterCommunity->painter->advance(1, glimmerSoul->color);
            if (directionSwitch) {
                painterCommunity->painter->rotate(M_PI / 16 * randomizer->generateProportion());
            } else {
                painterCommunity->painter->rotate(-M_PI / 16 * randomizer->generateProportion());
            }
            if (randomizer->generateProportion() > 0.8) {
                directionSwitch = !directionSwitch;
            }
        }
    }
};

class Wonk : public Lively {
public:
    GlimmerSoul *glimmerSoul;
    PainterCommunity *painterCommunity;

    Wonk(
            GlimmerSoul *glimmerSoul,
            PainterCommunity *painterCommunity
    ) :
            glimmerSoul{glimmerSoul},
            painterCommunity{painterCommunity} {
    }

    void live() {
        if (glimmerSoul->age == 0) {
            painterCommunity->painter->rotate(2 * M_PI * randomizer->generateProportion());
        }
        painterCommunity->painter->advance(1, glimmerSoul->color);
        if (glimmerSoul->age % 2 == 0) {
            painterCommunity->painter->rotate(M_PI / 16 * MAGNITUDE_AXIOM);
        }
    }
};
}
