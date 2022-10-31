#pragma once

#include "framework/Minimal.h"
#include "framework/Bindings.h"

namespace PROJECT_NAMESPACE {

class Lfo {
public:
    float current = 0.5;
    bool going_up = true;

    float tick() {
        if (current >= 1) {
            current = 1;
            going_up = false;
        }

        if (current <= 0) {
            current = 0;
            going_up = true;
        }

        if (going_up) {
            current += 0.0001 * OSCILLATION_AXIOM;
        } else {
            current -= 0.0001 * OSCILLATION_AXIOM;
        }
        return current;
    }
};

}
