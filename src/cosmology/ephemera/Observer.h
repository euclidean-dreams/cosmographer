#ifndef COSMOGRAPHER_OBSERVER_H
#define COSMOGRAPHER_OBSERVER_H

#include <ImpresarioUtils.h>

namespace cosmographer {

class Observer : impresarioUtils::Circulable {
    void activate() override;

    bool finished() override;
};

}

#endif //COSMOGRAPHER_OBSERVER_H
