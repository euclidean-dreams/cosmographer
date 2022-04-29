#include "Chromatica.h"
#include "cloister/chromatica/palette/CentrifugalPalette.h"
#include "cloister/chromatica/palette/BeatPalette.h"
#include "cloister/chromatica/palette/SingleColorPalette.h"
#include "cloister/chromatica/palette/ExplorerPalette.h"

namespace cosmographer {

Chromatica::Chromatica(
        CloisterCommunity *community
) :
        Liaison<ChromaticaCommunity>(community) {
    subCommunity.palette = mkup<CentrifugalPalette>(CONSTANTS->movingAverageSize);
    subCommunity.palette->initialize(&subCommunity);

}

HSLColor Chromatica::getColor() {
    return subCommunity.palette->getColor();
}

void Chromatica::experiencePhenomenon(const Phenomenon *phenomenon) {
    if (phenomenon->identity() == 3) {
        subCommunity.palette = mkup<ExplorerPalette>();
        subCommunity.palette->initialize(&subCommunity);
    } else if (phenomenon->identity() == 4) {
        subCommunity.palette = mkup<CentrifugalPalette>(CONSTANTS->movingAverageSize);
        subCommunity.palette->initialize(&subCommunity);
    }
//    else if (phenomenon->identity() == 2) {
//        subCommunity.palette = mkup<SingleColorPalette>();
//        subCommunity.palette->initialize(&subCommunity);
//    } else if (phenomenon->identity() == 3) {
//        subCommunity.palette = mkup<BeatPalette>();
//        subCommunity.palette->initialize(&subCommunity);
//    }

}

void Chromatica::experienceEssentia() {
    subCommunity.palette->experienceEssentia();
}

}
