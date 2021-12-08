#include "Cosmology.h"

namespace cosmographer {

Cosmology::Cosmology(impresarioUtils::BufferArbiter<const impresarioUtils::Parcel> &essentiology,
                     impresarioUtils::BufferArbiter<const impresarioUtils::Parcel> &phenomenology)
        : mutex{},
          aspect{std::make_unique<Plumage>(LATTICE_WIDTH, LATTICE_HEIGHT)},
          tick{0},
          concluded{false},
          essentiology{essentiology},
          phenomenology{phenomenology} {

}

std::unique_ptr<Lattice> Cosmology::observe() {
    std::unique_lock<std::mutex> lock{mutex};
    auto lattice = aspect->manifest(tick);
    tick++;
    return lattice;
}

void Cosmology::alter() {
    std::unique_lock<std::mutex> lock{mutex};
    auto newPhenomena = phenomenology.take();
    for (auto &phenomenon: *newPhenomena) {
        aspect->experiencePhenomenon(impresarioUtils::Unwrap::Phenomenon(*phenomenon));
    }
    auto newEssentia = essentiology.take();
    for (auto &essentia: *newEssentia) {
        aspect->experienceEssentia(impresarioUtils::Unwrap::Essentia(*essentia));
    }
}

void Cosmology::conclude() {
    concluded = true;
}

bool Cosmology::isConcluded() const {
    return concluded;
}

}
