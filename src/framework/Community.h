#ifndef COSMOGRAPHER_COMMUNITY_H
#define COSMOGRAPHER_COMMUNITY_H

#include "framework/Libs.h"
#include "framework/Macros.h"

namespace cosmographer {

class Paradigm;

class Community : public NonCopyable {
public:
    Paradigm *paradigm;

    Community(Paradigm *paradigm) : paradigm{paradigm} {}

    Community(Community *parentCommunity) : paradigm{parentCommunity->paradigm} {}
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
    Liaison(Paradigm *paradigm) : subCommunity{paradigm} {}

    Liaison(Community *community) : subCommunity{community} {}
};

class Constituent : public NonCopyable {
public:
    virtual ~Constituent() = default;
};

}

#endif //COSMOGRAPHER_COMMUNITY_H
