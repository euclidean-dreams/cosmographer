#ifndef COSMOGRAPHER_PARADIGM_H
#define COSMOGRAPHER_PARADIGM_H

#include "ImpresarioUtils.h"
#include "Config.h"
#include "Axiomology.h"

#define PARADIGM Paradigm::getInstance()
#define AXIOMOLOGY Paradigm::getInstance().getAxiomology()

namespace cosmographer {

class Paradigm : public impresarioUtils::NonCopyable {
private:
    static std::unique_ptr<Paradigm> instance;

    std::mutex mutex;
    std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter;
    std::shared_ptr<const Axiomology> axiomology;
    uint latticeWidth;
    uint latticeHeight;

    explicit Paradigm(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter);

public:
    static Paradigm &getInstance();

    static void initialize(std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomologyArbiter);

    void refresh();

    std::shared_ptr<const Axiomology> getAxiomology();

    uint getLatticeWidth() const;

    uint getLatticeHeight() const;
};

}

#endif //COSMOGRAPHER_PARADIGM_H
