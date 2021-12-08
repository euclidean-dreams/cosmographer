#include "AnalogoriumPercipient.h"

namespace cosmographer {

AnalogoriumPercipient::AnalogoriumPercipient(std::unique_ptr<impresarioUtils::NetworkSocket> socket,
                                         std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> essentiology)
        : socket{move(socket)},
          essentiology{move(essentiology)} {

}

void AnalogoriumPercipient::activate() {
    auto parcel = socket->receiveParcel();
    if (parcel->getIdentifier() == ImpresarioSerialization::Identifier::essentia) {
        essentiology->give(move(parcel));
    }
}

uint64_t AnalogoriumPercipient::getTickInterval() {
    return 0;
}

bool AnalogoriumPercipient::finished() {
    return false;
}

}
