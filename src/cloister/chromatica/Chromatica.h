#ifndef COSMOGRAPHER_CHROMATICA_H
#define COSMOGRAPHER_CHROMATICA_H

#include "ChromaticaCommunity.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class Chromatica : public Liaison<ChromaticaCommunity> {
public:
    Chromatica(

    );

    HSLColor getColor();

    void experiencePhenomenon(const Phenomenon *phenomenon);

    void experienceEssentia();

};

}

#endif //COSMOGRAPHER_CHROMATICA_H
