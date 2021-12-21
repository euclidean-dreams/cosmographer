#ifndef COSMOGRAPHER_ANALOGORIUMPERCIPIENT_H
#define COSMOGRAPHER_ANALOGORIUMPERCIPIENT_H

#include <ImpresarioUtils.h>

namespace cosmographer {

class AnalogoriumPercipient : public impresarioUtils::Circulable {
private:
    std::unique_ptr<impresarioUtils::NetworkSocket> socket;
    std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> essentiology;

public:
    AnalogoriumPercipient(std::unique_ptr<impresarioUtils::NetworkSocket> socket,
                        std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> essentiology);

    void activate() override;

    uint64_t getTickInterval() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_ANALOGORIUMPERCIPIENT_H
