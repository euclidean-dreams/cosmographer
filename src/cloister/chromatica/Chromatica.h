#ifndef COSMOGRAPHER_CHROMATICA_H
#define COSMOGRAPHER_CHROMATICA_H

#include "cloister/CloisterCommunity.h"
#include "ChromaticaCommunity.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class Chromatica : public Fellow<CloisterCommunity>, public Liaison<ChromaticaCommunity> {
public:
    Chromatica(
            CloisterCommunity *community
    );

    HSLColor getColor();

    void experiencePhenomenon(const Phenomenon *phenomenon);

    void experienceEssentia(const Essentia *essentia);

};

}

#endif //COSMOGRAPHER_CHROMATICA_H
