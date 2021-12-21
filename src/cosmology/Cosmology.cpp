#include "Cosmology.h"

namespace cosmographer {

Cosmology::Cosmology(impresarioUtils::BufferArbiter<const impresarioUtils::Parcel> &essentiology,
                     impresarioUtils::BufferArbiter<const impresarioUtils::Parcel> &phenomenology)
        : mutex{},
          rootAffinity{nullptr},
          tick{0},
          concluded{false},
          essentiology{essentiology},
          phenomenology{phenomenology} {
    auto aspect = std::make_unique<Plumage>(1.0, 1.0);
    rootAffinity = std::make_unique<PassthroughAffinity>(move(aspect));
}

std::unique_ptr<Lattice> Cosmology::observe() {
    std::unique_lock<std::mutex> lock{mutex};
    auto lattice = rootAffinity->manifest(tick);
    tick++;
    return lattice;
}

void Cosmology::alter() {
    std::unique_lock<std::mutex> lock{mutex};
    auto newPhenomenonParcels = phenomenology.take();
    for (auto &phenomenonParcel: *newPhenomenonParcels) {
        auto phenomenon = impresarioUtils::Unwrap::Phenomenon(*phenomenonParcel);
        auto button = phenomenon->identity();
        if (button == 6) {
            auto aspect = std::make_unique<Plumage>(1.0, 1.0);
            rootAffinity = std::make_unique<PassthroughAffinity>(move(aspect));
        } else if (button == 7) {
            auto aspect = std::make_unique<Bursting>(1.0, 1.0);
            rootAffinity = std::make_unique<PassthroughAffinity>(move(aspect));
        } else if (button == 8) {
            auto aspect = std::make_unique<Dragonarium>(1.0);
            rootAffinity = std::make_unique<PassthroughAffinity>(move(aspect));
        } else if (button == 9) {
            auto aspects = std::make_unique<std::vector<std::unique_ptr<Aspect>>>();
            aspects->push_back(std::make_unique<Dragonarium>(1.0));
            aspects->push_back(std::make_unique<Plumage>(0.5, 0.5));
            rootAffinity = std::make_unique<OverlapAffinity>(move(aspects));
        } else if (button == 10) {
            auto aspects = std::make_unique<std::vector<std::unique_ptr<Aspect>>>();
            aspects->push_back(std::make_unique<Dragonarium>(1.0));
            aspects->push_back(std::make_unique<Plumage>(1.0, 1.0));
            aspects->push_back(std::make_unique<Bursting>(1.0, 1.0));
            rootAffinity = std::make_unique<SlottedAffinity>(move(aspects));
        }

        rootAffinity->experiencePhenomenon(phenomenon);
    }
    auto newEssentia = essentiology.take();
    for (auto &essentia: *newEssentia) {
        rootAffinity->experienceEssentia(impresarioUtils::Unwrap::Essentia(*essentia));
    }
}

void Cosmology::conclude() {
    concluded = true;
}

bool Cosmology::isConcluded() const {
    return concluded;
}

}
