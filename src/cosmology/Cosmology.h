#ifndef COSMOGRAPHER_COSMOLOGY_H
#define COSMOGRAPHER_COSMOLOGY_H

#include <mutex>
#include <ImpresarioUtils.h>
#include "gizmo/paradigm/Paradigm.h"
#include "gizmo/Lattice.h"
#include "cosmology/aspect/Plumage.h"
#include "cosmology/aspect/Signalarium.h"
#include "cosmology/aspect/Dragonarium.h"
#include "cosmology/aspect/Bursting.h"
#include "cosmology/affinity/OverlapAffinity.h"
#include "cosmology/affinity/PassthroughAffinity.h"
#include "cosmology/affinity/SlottedAffinity.h"

namespace cosmographer {

class Cosmology : public impresarioUtils::NonCopyable {
private:
    std::mutex mutex;
    std::unique_ptr<Affinity> rootAffinity;
    int tick;
    bool concluded;
    impresarioUtils::BufferArbiter<const impresarioUtils::Parcel> &essentiology;
    impresarioUtils::BufferArbiter<const impresarioUtils::Parcel> &phenomenology;

public:
    explicit Cosmology(impresarioUtils::BufferArbiter<const impresarioUtils::Parcel> &essentiology,
                       impresarioUtils::BufferArbiter<const impresarioUtils::Parcel> &phenomenology);

    std::unique_ptr<Lattice> observe();

    void alter();

    void conclude();

    bool isConcluded() const;
};

}

#endif //COSMOGRAPHER_COSMOLOGY_H
