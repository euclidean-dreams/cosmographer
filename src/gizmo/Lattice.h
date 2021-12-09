#ifndef COSMOGRAPHER_LATTICE_H
#define COSMOGRAPHER_LATTICE_H

#include <ImpresarioUtils.h>
#include "gizmo/paradigm/Paradigm.h"
#include "gizmo/color/HSLColor.h"
#include "gizmo/Coordinate.h"

namespace cosmographer {

class Lattice : public impresarioUtils::NonCopyable {
private:
    std::vector<std::vector<HSLColor>> data;

public:
    Lattice();

    HSLColor getColor(Coordinate coordinate) const;

    void setColor(Coordinate coordinate, HSLColor color);

    void setColorIfValid(Coordinate coordinate, HSLColor color);

    bool isValid(Coordinate coordinate) const;

    int width() const;

    int height() const;

    int size() const;
};

}

#endif //COSMOGRAPHER_LATTICE_H
