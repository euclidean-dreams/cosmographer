#ifndef COSMOGRAPHER_VANTAGE_H
#define COSMOGRAPHER_VANTAGE_H

#include <ImpresarioUtils.h>
#include "Paradigm.h"
#include "gizmo/Lattice.h"

namespace cosmographer {

class Vantage : public impresarioUtils::NonCopyable {
public:
    virtual ~Vantage() = default;

    virtual void send(const Lattice &lattice) = 0;

    virtual int getRefreshRate() = 0;
};

}

#endif //COSMOGRAPHER_VANTAGE_H
