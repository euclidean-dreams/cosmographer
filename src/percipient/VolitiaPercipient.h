#ifndef COSMOGRAPHER_VOLITIAPERCIPIENT_H
#define COSMOGRAPHER_VOLITIAPERCIPIENT_H

#include <ImpresarioUtils.h>

namespace cosmographer {

class VolitiaPercipient : public impresarioUtils::Circulable {
private:
    std::unique_ptr<impresarioUtils::NetworkSocket> socket;
    std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomology;
    std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology;

public:
    VolitiaPercipient(std::unique_ptr<impresarioUtils::NetworkSocket> socket,
                     std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomology,
                     std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology);

    void activate() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_VOLITIAPERCIPIENT_H
