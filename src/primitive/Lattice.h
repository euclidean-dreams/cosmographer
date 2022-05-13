#ifndef COSMOGRAPHER_LATTICE_H
#define COSMOGRAPHER_LATTICE_H

#include "framework/Minimal.h"
#include "primitive/color/HSLColor.h"
#include "primitive/Loci.h"

namespace cosmographer {

class Lattice : public NonCopyable {
private:
    umap<Coordinate, HSLColor, CoordinateHash> dots;

public:
    int width;
    int height;
    HSLColor nullColor;

    explicit Lattice(
            uint width,
            uint height,
            HSLColor nullColor
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

    void meld(
            Lattice &other
    );
};

}

#endif //COSMOGRAPHER_LATTICE_H
