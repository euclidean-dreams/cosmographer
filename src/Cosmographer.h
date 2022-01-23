#ifndef COSMOGRAPHER_COSMOGRAPHER_H
#define COSMOGRAPHER_COSMOGRAPHER_H

#include <ImpresarioUtils.h>
#include "vantage/Vantage.h"
#include "cosmology/Cosmology.h"
#include "gizmo/paradigm/Paradigm.h"

namespace cosmographer {

class Cosmographer : public impresarioUtils::Circulable {
private:
    std::unique_ptr<Vantage> vantage;
    std::unique_ptr<Cosmology> cosmology;
    std::unique_ptr<impresarioUtils::NetworkSocket> essentiaSocket;
    std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology;

    std::vector<std::unique_ptr<impresarioUtils::Parcel>> receiveEssentiaParcelBundle();

public:
    explicit Cosmographer(std::unique_ptr<Vantage> vantage,
                          std::unique_ptr<impresarioUtils::NetworkSocket> essentiaSocket,
                          std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology);

    void activate() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_COSMOGRAPHER_H
