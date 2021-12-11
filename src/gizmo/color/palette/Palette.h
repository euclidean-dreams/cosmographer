#ifndef COSMOGRAPHER_PALETTE_H
#define COSMOGRAPHER_PALETTE_H

#include <ImpresarioUtils.h>
#include "gizmo/paradigm/Paradigm.h"
#include "gizmo/color/HSLColor.h"
#include "gizmo/color/Colorology.h"

namespace cosmographer {

class Palette : public impresarioUtils::NonCopyable {
public:
    virtual HSLColor getColor(int index) = 0;

    virtual void experienceEssentia(const ImpresarioSerialization::Essentia *essentia) = 0;
};

}

#endif //COSMOGRAPHER_PALETTE_H
