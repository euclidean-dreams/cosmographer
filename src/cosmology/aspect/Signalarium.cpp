#include "Signalarium.h"

namespace cosmographer {

Signalarium::Signalarium()
        : signal{nullptr},
          colorium{std::make_unique<JourneyColorium>(PARADIGM.getLatticeWidth() * PARADIGM.getLatticeHeight())} {

}

std::unique_ptr<Lattice> Signalarium::manifest(int tick) {
    auto lattice = std::make_unique<Lattice>();
    if (signal != nullptr) {
        signal->illuminate(*lattice);
    }
    return lattice;
}

void Signalarium::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    colorium->experiencePhenomenon(phenomenon);
}

void Signalarium::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    auto mels = essentia->melSignal();
    std::vector<float> collectedMels{};
    collectedMels.reserve(mels->size());
    for (int index = 0; index < mels->size(); index++) {
        collectedMels.push_back(mels->Get(index));
    }
    signal = std::make_unique<Signal>(colorium->getColor(), move(collectedMels));
}

}
