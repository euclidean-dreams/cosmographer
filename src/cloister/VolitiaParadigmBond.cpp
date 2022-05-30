#include "VolitiaParadigmBond.h"
#include "Default.h"

namespace cosmographer {

VolitiaParadigmBond::VolitiaParadigmBond(
        sp<Arbiter<const Parcel>> arbiter
) :
        arbiter{mv(arbiter)} {

}

void VolitiaParadigmBond::refresh() {
    if (arbiter->newDataAvailable()) {
        auto axiomologyParcel = arbiter->take();
        auto newAxioms = Unwrap::Axiomology(*axiomologyParcel)->axioms();
        if (newAxioms->size() == axioms.size()) {
            for (int index = 0; index < axioms.size(); index++) {
                axioms[index] = newAxioms->Get(index);
            }
        }
    }
}
}
