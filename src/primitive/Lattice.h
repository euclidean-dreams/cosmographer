#ifndef COSMOGRAPHER_LATTICE_H
#define COSMOGRAPHER_LATTICE_H

#include "framework/Minimal.h"
#include "primitive/color/HSLColor.h"
#include "primitive/Loci.h"

namespace cosmographer {

class Lattice : public NonCopyable {
private:
    vec<vec<HSLColor>> data;

public:
    int width;
    int height;

    explicit Lattice(
            uint width,
            uint height,
            HSLColor initialColor
    );

    HSLColor getColor(
            int x,
            int y
    ) const;

    void setColor(
            int x,
            int y,
            HSLColor color
    );

    int size() const;

    bool isValid(
            int x,
            int y
    ) const;
};

}

#endif //COSMOGRAPHER_LATTICE_H
