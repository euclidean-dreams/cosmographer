#include "VolitiaPercipient.h"

namespace cosmographer {

VolitiaPercipient::VolitiaPercipient(std::unique_ptr<impresarioUtils::NetworkSocket> socket,
                                     std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomology,
                                     std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology)
        : socket{move(socket)},
          axiomology{move(axiomology)},
          phenomenology{move(phenomenology)} {

}

void VolitiaPercipient::activate() {
    auto parcel = socket->receiveParcel();
    if (parcel->getIdentifier() == ImpresarioSerialization::Identifier::axiomology) {
        axiomology->give(move(parcel));
    } else if (parcel->getIdentifier() == ImpresarioSerialization::Identifier::phenomenon) {
        phenomenology->give(move(parcel));
    }
}

uint64_t VolitiaPercipient::getTickInterval() {
    return 0;
}

bool VolitiaPercipient::finished() {
    return false;
}

}
