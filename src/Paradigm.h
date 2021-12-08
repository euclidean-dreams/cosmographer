#ifndef COSMOGRAPHER_PARADIGM_H
#define COSMOGRAPHER_PARADIGM_H

#include <ImpresarioUtils.h>
#include "Config.h"

namespace cosmographer {

class Paradigm : public impresarioUtils::NonCopyable {
private:
    static std::unique_ptr<Paradigm> instance;

    std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter;

    explicit Paradigm(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter);

public:
    static Paradigm &getInstance();

    static void initialize(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter);

    std::shared_ptr<const impresarioUtils::Parcel> getAxiomology() const;
};

}

#endif //COSMOGRAPHER_PARADIGM_H
