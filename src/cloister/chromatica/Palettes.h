#pragma once

#include "palette/Palette.h"
#include "oddments/Oddments.h"

namespace PROJECT_NAMESPACE {

class SingleColorPalette : public Palette {
public:
    HSLColor get_color() override {
        return jitter({cast(int, COLOR_BASE_AXIOM * HSL_HUE_MAX), 100, 50});
    }
};

class  LfoPalette: public Palette {
private:
    Lfo lfo = {};

public:
    HSLColor get_color() override {
        auto base_hue = COLOR_BASE_AXIOM * HSL_HUE_MAX;
        base_hue += 100 - (200 * COLOR_ACCENT_AXIOM * lfo.tick());
        return {base_hue, 100, 50};
    }
};

}
