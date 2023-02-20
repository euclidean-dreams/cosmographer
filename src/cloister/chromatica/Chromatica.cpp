#include "Chromatica.h"
#include "cloister/chromatica/palette/CentrifugalPalette.h"
#include "cloister/chromatica/palette/BeatPalette.h"
#include "cloister/chromatica/palette/RandomPalette.h"
#include "Palettes.h"

namespace cosmographer {

Chromatica::Chromatica(
) :
        Liaison<ChromaticaCommunity>(paradigm) {
    subCommunity.palette = mkup<LfoPalette>();
    subCommunity.palette->initialize(&subCommunity);

}

HSLColor Chromatica::getColor() {
    return subCommunity.palette->get_color();
}

void Chromatica::experiencePhenomenon(const Phenomenon *phenomenon) {
    if (phenomenon->identity() == 200) {
        subCommunity.palette = mkup<LfoPalette>();
        subCommunity.palette->initialize(&subCommunity);
    } else if (phenomenon->identity() == 201) {
        subCommunity.palette = mkup<CentrifugalPalette>(constants->signalAverageSize);
        subCommunity.palette->initialize(&subCommunity);
    } else if (phenomenon->identity() == 202) {
        subCommunity.palette = mkup<ExplorerPalette>();
        subCommunity.palette->initialize(&subCommunity);
    } else if (phenomenon->identity() == 203) {
        subCommunity.palette = mkup<RandomPalette>();
        subCommunity.palette->initialize(&subCommunity);
    } else if (phenomenon->identity() == 204) {
        subCommunity.palette = mkup<SingleColorPalette>();
        subCommunity.palette->initialize(&subCommunity);
    }

}

void Chromatica::experienceEssentia() {
    subCommunity.palette->experienceEssentia();
}

}
