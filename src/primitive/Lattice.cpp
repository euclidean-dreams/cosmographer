#include "Lattice.h"

namespace cosmographer {

Lattice::Lattice(
        uint width,
        uint height,
        HSLColor nullColor
) :
        data{
                width,
                {height,
                 nullColor
                }
        },
//        dots{},
        width{cast(int, width)},
        height{cast(int, height)},
        nullColor{nullColor} {

}

HSLColor Lattice::getColor(
        int x,
        int y
) const {
    return data[x][y];
//    auto dot = dots.find({x, y});
//    if (dot != dots.end()) {
//        return dot->second;
//    } else {
//        return nullColor;
//    }
}

void Lattice::setColor(
        int x,
        int y,
        HSLColor color
) {
    data[x][y] = color;
//    dots.insert_or_assign({x, y}, color);
}

int Lattice::size() const {
    return width * height;
}

bool Lattice::isValid(
        int x,
        int y
) const {
    if (x >= 0 && x < width) {
        if (y >= 0 && y < height) {
            return true;
        }
    }
    return false;
}

void Lattice::meld(Lattice &other) {
//    for (auto &dot: other.dots) {
//        if (dots.find(dot.first) == dots.end()) {
//            dots.insert_or_assign(dot.first, dot.second);
//        }
//    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto potentialColor = other.getColor(x, y);
            if (potentialColor != nullColor) {
                setColor(x, y, potentialColor);
            }
        }
    }
}

}
