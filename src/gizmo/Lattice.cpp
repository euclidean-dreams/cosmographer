#include "Lattice.h"

namespace cosmographer {

Lattice::Lattice()
        : data{PARADIGM.getLatticeWidth(), {PARADIGM.getLatticeHeight(), HSLColor{0, 0, 0}}} {

}

HSLColor Lattice::getColor(Coordinate coordinate) const {
    return data[coordinate.x][coordinate.y];
}

void Lattice::setColor(Coordinate coordinate, HSLColor color) {
    data[coordinate.x][coordinate.y] = color;
}

void Lattice::setColorIfValid(Coordinate coordinate, HSLColor color) {
    if (isValid(coordinate)) {
        setColor(coordinate, color);
    }
}

bool Lattice::isValid(Coordinate coordinate) const {
    if (coordinate.x >= 0 && coordinate.x < width()) {
        if (coordinate.y >= 0 && coordinate.y < height()) {
            return true;
        }
    }
    return false;
}

int Lattice::width() const {
    return static_cast<int>(data.size());
}

int Lattice::height() const {
    return static_cast<int>(data[0].size());
}

int Lattice::size() const {
    return width() * height();
}

}
