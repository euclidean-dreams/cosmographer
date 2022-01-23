#include "Signalarium.h"

namespace cosmographer {

Signalarium::Signalarium()
        : colorium{std::make_unique<JourneyColorium>(PARADIGM.getLatticeWidth() * PARADIGM.getLatticeHeight())},
          signal{} {

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
    colorium->experienceEssentia(essentia);
    std::vector<float> frame{};
    auto samples = essentia->melSignal();
    frame.reserve(samples->size());
    for (int index = 0; index < samples->size(); index++) {
        auto sample = samples->Get(index);
        frame.push_back(sample);
    }
    signal = std::make_unique<Signal>(Coordinate{0, 0}, colorium->getColor(), move(frame));
}

}
