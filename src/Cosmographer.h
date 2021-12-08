#ifndef COSMOGRAPHER_COSMOGRAPHER_H
#define COSMOGRAPHER_COSMOGRAPHER_H

#include <ImpresarioUtils.h>
#include "vantage/Vantage.h"
#include "cosmology/Cosmology.h"
#include "Paradigm.h"
#include "Empyrium.h"

namespace cosmographer {

class Cosmographer : public impresarioUtils::Circulable {
private:
    std::unique_ptr<Vantage> vantage;
    std::shared_ptr<Cosmology> cosmology;
    std::unique_ptr<std::thread> empyriumThread;
    std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> essentiology;
    std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology;

public:
    explicit Cosmographer(std::unique_ptr<Vantage> vantage,
                          std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> essentiology,
                          std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology);

    void activate() override;

    uint64_t getTickInterval() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_COSMOGRAPHER_H
