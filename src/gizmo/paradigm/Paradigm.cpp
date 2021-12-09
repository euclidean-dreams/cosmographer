#include "Paradigm.h"

namespace cosmographer {

std::unique_ptr<Paradigm> Paradigm::instance = nullptr;

void Paradigm::initialize(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter) {
    if (instance == nullptr) {
        instance = std::unique_ptr<Paradigm>(new Paradigm(move(axiomologyArbiter)));
    } else {
        throw std::logic_error("Attempted to initialize Paradigm singleton more than once");
    }
}

Paradigm::Paradigm(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter)
        : axiomologyArbiter{move(axiomologyArbiter)},
          axiomology{nullptr},
          latticeWidth{LATTICE_WIDTH},
          latticeHeight{LATTICE_HEIGHT} {
    auto wildcards = std::vector<float>{};
    wildcards.resize(100, 0);
    axiomology = std::make_shared<Axiomology>(INITIAL_BRIGHTNESS, 0.5, 0, wildcards);
}

Paradigm &Paradigm::getInstance() {
    return *instance;
}

void Paradigm::refresh() {
    std::unique_lock<std::mutex> lock{mutex};
    auto axiomologyParcel = axiomologyArbiter->take();
    if (axiomologyParcel != nullptr) {
        axiomology = std::make_shared<Axiomology>(*axiomologyParcel);
    }
}

std::shared_ptr<const Axiomology> Paradigm::getAxiomology() {
    std::unique_lock<std::mutex> lock{mutex};
    return axiomology;
}

uint Paradigm::getLatticeWidth() const {
    return latticeWidth;
}

uint Paradigm::getLatticeHeight() const {
    return latticeHeight;
}

}
