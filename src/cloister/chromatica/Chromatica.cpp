#include "Chromatica.h"
#include "cloister/chromatica/palette/CentrifugalPalette.h"
#include "cloister/chromatica/palette/BeatPalette.h"
#include "cloister/chromatica/palette/SingleColorPalette.h"

namespace cosmographer {

Chromatica::Chromatica(
        CloisterCommunity *community
) :
        Liaison<ChromaticaCommunity>(community) {
    subCommunity.palette = mkup<CentrifugalPalette>(community->paradigm->cloister->constants->movingAverageSize);
    subCommunity.palette->initialize(&subCommunity);

}

HSLColor Chromatica::getColor() {
    return subCommunity.palette->getColor();
}

void Chromatica::experiencePhenomenon(const Phenomenon *phenomenon) {
    if (phenomenon->identity() == 0) {
        subCommunity.palette = mkup<CentrifugalPalette>(CONSTANTS->movingAverageSize);
        subCommunity.palette->initialize(&subCommunity);
    } else if (phenomenon->identity() == 1) {
        subCommunity.palette = mkup<BeatPalette>();
        subCommunity.palette->initialize(&subCommunity);
    } else if (phenomenon->identity() == 2) {
        subCommunity.palette = mkup<SingleColorPalette>();
        subCommunity.palette->initialize(&subCommunity);
    }

}

void Chromatica::experienceEssentia(const Essentia *essentia) {
    subCommunity.palette->experienceEssentia(essentia);
}

}
