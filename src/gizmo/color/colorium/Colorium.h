#ifndef COSMOGRAPHER_COLORIUM_H
#define COSMOGRAPHER_COLORIUM_H

#include <ImpresarioUtils.h>
#include "gizmo/color/palette/Palette.h"

namespace cosmographer {

class Colorium : public impresarioUtils::NonCopyable {
protected:
    std::unique_ptr<Palette> palette;

public:
    explicit Colorium(std::unique_ptr<Palette> palette);

    HSLColor getColor();

    HSLColor getColor(int index);

    virtual void experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) = 0;

};

}

#endif //COSMOGRAPHER_COLORIUM_H
