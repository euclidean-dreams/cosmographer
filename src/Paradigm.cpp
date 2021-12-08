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
        : axiomologyArbiter{move(axiomologyArbiter)} {

}

Paradigm &Paradigm::getInstance() {
    return *instance;
}

std::shared_ptr<const impresarioUtils::Parcel> Paradigm::getAxiomology() const {
    return axiomologyArbiter->take();
}

}
