#ifndef COSMOGRAPHER_COMMUNITY_H
#define COSMOGRAPHER_COMMUNITY_H

#include "framework/Libs.h"
#include "framework/Macros.h"

namespace cosmographer {

class Paradigm;

class Community : public NonCopyable {
public:
    ~Community() = default;
};

template<class Community>
class Fellow : public NonCopyable {
protected:
    Community *community;

public:
    void initialize(Community *associatedCommunity) {
        community = associatedCommunity;
    }
};

template<class SubCommunity>
class Liaison : public NonCopyable {
protected:
    SubCommunity subCommunity;

public:
    Liaison(Paradigm *paradigm) {}

    Liaison(Community *community) {}
};

}

#endif //COSMOGRAPHER_COMMUNITY_H
