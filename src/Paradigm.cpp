#include "Paradigm.h"

namespace cosmographer {

std::unique_ptr<Paradigm> Paradigm::instance = nullptr;

void Paradigm::initialize(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter) {
    if (instance == nullptr) {
        instance = std::unique_ptr<Paradigm>(new Paradigm(move(axiomologyArbiter))
        );
        instance->refresh();
    } else {
        throw std::logic_error("Attempted to initialize Paradigm singleton more than once");
    }
}

Paradigm::Paradigm(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter)
        : axiomologyArbiter{move(axiomologyArbiter)},
          currentAxiomologyParcel{generateDefaultAxiomology()} {

}

Paradigm &Paradigm::getInstance() {
    return *instance;
}

void Paradigm::refresh() {
    auto potentialAxiomologyParcel = axiomologyArbiter->take();
    if (potentialAxiomologyParcel != nullptr) {
        currentAxiomologyParcel = move(potentialAxiomologyParcel);
    }
}

const ImpresarioSerialization::Axiomology *Paradigm::getAxiomology() const {
    return impresarioUtils::Unwrap::Axiomology(*currentAxiomologyParcel);
}

std::shared_ptr<const impresarioUtils::Parcel> Paradigm::generateDefaultAxiomology() {
    // this headache is due to the fact that we're holding on to a parcel for the axiomology
    // in order to have a default axiomology, we need to go through the whole zmq song and dance
    flatbuffers::FlatBufferBuilder identifierWrapperBuilder{};
    auto serializedIdentifier = ImpresarioSerialization::CreateIdentifierWrapper(identifierWrapperBuilder,
                                                                                 ImpresarioSerialization::Identifier::axiomology);
    identifierWrapperBuilder.Finish(serializedIdentifier);
    flatbuffers::FlatBufferBuilder axiomologyBuilder{};
    auto axiomology = ImpresarioSerialization::CreateAxiomology(axiomologyBuilder, 0, 0, 0, INITIAL_BRIGHTNESS);
    axiomologyBuilder.Finish(axiomology);
    auto envelope = std::make_unique<zmq::multipart_t>();
    envelope->addmem(identifierWrapperBuilder.GetBufferPointer(), identifierWrapperBuilder.GetSize());
    envelope->addmem(axiomologyBuilder.GetBufferPointer(), axiomologyBuilder.GetSize());
    auto identifierWrapper = envelope->pop();
    auto payload = envelope->pop();
    return std::make_unique<const impresarioUtils::Parcel>(identifierWrapper, payload);
}

}
