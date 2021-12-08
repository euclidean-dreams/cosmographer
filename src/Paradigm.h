#ifndef COSMOGRAPHER_PARADIGM_H
#define COSMOGRAPHER_PARADIGM_H

#include <ImpresarioUtils.h>
#include "Config.h"

namespace cosmographer {

class Paradigm : public impresarioUtils::NonCopyable {
private:
    static std::unique_ptr<Paradigm> instance;

    std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter;
    std::shared_ptr<const impresarioUtils::Parcel> currentAxiomologyParcel;

    explicit Paradigm(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter);

    static std::shared_ptr<const impresarioUtils::Parcel> generateDefaultAxiomology();

public:
    static Paradigm &getInstance();

    static void initialize(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter);

    void refresh();

    const ImpresarioSerialization::Axiomology *getAxiomology() const;
};

}

#endif //COSMOGRAPHER_PARADIGM_H
