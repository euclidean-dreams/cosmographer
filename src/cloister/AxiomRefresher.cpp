#include "AxiomRefresher.h"
#include "Default.h"

namespace cosmographer {

AxiomRefresher::AxiomRefresher(
        sp<Arbiter<const Parcel>> axiomArbiter
) :
        axiomArbiter{mv(axiomArbiter)} {

}

void AxiomRefresher::refresh() {
    if (axiomArbiter->newDataAvailable()) {
        auto axiomologyParcel = axiomArbiter->take();
        auto newAxioms = Unwrap::Axiomology(*axiomologyParcel)->axioms();
        if (newAxioms->size() == community->paradigm->axioms.size()) {
            for (int index = 0; index < community->paradigm->axioms.size(); index++) {
                community->paradigm->axioms[index] = newAxioms->Get(index);
            }
        }
    }
}
}
