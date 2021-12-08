#include "Cosmographer.h"

namespace cosmographer {

Cosmographer::Cosmographer(std::unique_ptr<Vantage> vantage,
                           std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> essentiology,
                           std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology)
        : vantage{move(vantage)},
          cosmology{nullptr},
          empyriumThread{nullptr},
          essentiology{move(essentiology)},
          phenomenology{move(phenomenology)} {
    cosmology = std::make_shared<Cosmology>(*this->essentiology, *this->phenomenology);
    auto empyrium = std::make_unique<Empyrium>(cosmology);
    empyriumThread = impresarioUtils::Circlet::begin(move(empyrium));
}

void Cosmographer::activate() {
    auto lattice = cosmology->observe();
    vantage->send(*lattice);
}

uint64_t Cosmographer::getTickInterval() {
    return vantage->getRefreshRate();
}

bool Cosmographer::finished() {
    return false;
}

}
