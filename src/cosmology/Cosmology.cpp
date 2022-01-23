#include "Cosmology.h"

namespace cosmographer {

Cosmology::Cosmology()
        : rootAffinity{nullptr},
          tick{0},
          concluded{false} {
//    auto aspect = std::make_unique<Plumage>(1.0, 1.0);
    auto aspect = std::make_unique<Signalarium>();
    rootAffinity = std::make_unique<PassthroughAffinity>(move(aspect));
}

std::unique_ptr<Lattice> Cosmology::observe() {
    auto lattice = rootAffinity->manifest(tick);
    tick++;
    return lattice;
}

void Cosmology::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    auto button = phenomenon->identity();
    if (button == 5) {
        auto aspect = std::make_unique<Plumage>(1.0, 1.0);
        rootAffinity = std::make_unique<PassthroughAffinity>(move(aspect));
    } else if (button == 6) {
        auto aspect = std::make_unique<Bursting>(1.0, 1.0);
        rootAffinity = std::make_unique<PassthroughAffinity>(move(aspect));
    } else if (button == 7) {
        auto aspect = std::make_unique<Dragonarium>(1.0);
        rootAffinity = std::make_unique<PassthroughAffinity>(move(aspect));
    } else if (button == 8) {
        auto aspects = std::make_unique<std::vector<std::unique_ptr<Aspect>>>();
        aspects->push_back(std::make_unique<Dragonarium>(1.0));
        aspects->push_back(std::make_unique<Plumage>(0.5, 0.5));
        rootAffinity = std::make_unique<OverlapAffinity>(move(aspects));
    } else if (button == 9) {
        auto aspects = std::make_unique<std::vector<std::unique_ptr<Aspect>>>();
        aspects->push_back(std::make_unique<Dragonarium>(1.0));
        aspects->push_back(std::make_unique<Plumage>(1.0, 1.0));
        aspects->push_back(std::make_unique<Bursting>(1.0, 1.0));
        rootAffinity = std::make_unique<SlottedAffinity>(move(aspects));
    }
    rootAffinity->experiencePhenomenon(phenomenon);
}

void Cosmology::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    rootAffinity->experienceEssentia(essentia);
}

void Cosmology::conclude() {
    concluded = true;
}

bool Cosmology::isConcluded() const {
    return concluded;
}

}
