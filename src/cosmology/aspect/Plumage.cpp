#include "Plumage.h"

namespace cosmographer {

Plumage::Plumage(uint latticeWidth, uint latticeHeight)
        : Aspect{latticeWidth, latticeHeight},
          ecosystem{} {

}

std::unique_ptr<Lattice> Plumage::manifest(int tick) {
    auto lattice = std::make_unique<Lattice>(latticeWidth, latticeHeight);
    ecosystem.observe(*lattice);
    return lattice;
}

void Plumage::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {

}

void Plumage::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    auto samples = essentia->radixes();
    for (int index = 0; index < samples->size(); index++) {
        auto sample = samples->Get(index);
        if (sample < 0) {
            sample = 0;
        }

        // due to mel filterbank overflow, that last triangular filter catches everything above it
        // accommodate for crazy large last sample - this will go once those ridiculous triangular filters are changed
        if (index == samples->size() - 1) {
            sample /= 100;
        }

        if (sample > 50) {
            HSLColor color{static_cast<int>(samples->size()), index, 300, 100, 50};
            auto bloom = std::make_unique<Bloom>(CoordinateTransformer::verticalWrap(index, latticeWidth), color);
            ecosystem.add(move(bloom));
        }
    }
}

}
