#ifndef COSMOGRAPHER_RANDOMPALETTE_H
#define COSMOGRAPHER_RANDOMPALETTE_H

#include "Palette.h"

namespace cosmographer {

class RandomPalette : public Palette {
public:
    HSLColor getColor() override;
};

}

#endif //COSMOGRAPHER_RANDOMPALETTE_H
