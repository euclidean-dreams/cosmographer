#ifndef COSMOGRAPHER_ELEMENT_H
#define COSMOGRAPHER_ELEMENT_H

#include "Paradigm.h"

namespace cosmographer {

class Element : public NonCopyable {
public:
    virtual ~Element() = default;
};

}

#endif //COSMOGRAPHER_ELEMENT_H
