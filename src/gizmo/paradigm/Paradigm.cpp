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
          axiomology{std::make_unique<Axiomology>()},
          latticeWidth{LATTICE_WIDTH},
          latticeHeight{LATTICE_HEIGHT} {

}

Paradigm &Paradigm::getInstance() {
    return *instance;
}

void Paradigm::refresh() {
    if (axiomologyArbiter->newDataAvailable()) {
        auto axiomologyParcel = axiomologyArbiter->take();
        axiomology = std::make_unique<Axiomology>(*axiomologyParcel);
    }
}

const Axiomology &Paradigm::getAxiomology() {
    return *axiomology;
}

uint Paradigm::getLatticeWidth() const {
    return latticeWidth;
}

uint Paradigm::getLatticeHeight() const {
    return latticeHeight;
}

}
