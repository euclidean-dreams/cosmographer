#include "Lindogram.h"

namespace cosmographer {

Lindogram::Lindogram(Coordinate origin, HSLColor soulColor, double orientation)
        : Illuminable(origin, soulColor),
          location{static_cast<double>(origin.x), static_cast<double>(origin.y)},
          initialOrientation{orientation},
          orientation{orientation},
          state{},
          currentTimeling{0} {

}

void Lindogram::illuminate(Lattice &lattice) {
    location = {static_cast<double>(origin.x), static_cast<double>(origin.y)};
    orientation = initialOrientation;
    std::vector<Coordinate> renderableCoordinates;
    for (int timeling = 0; timeling < currentTimeling && timeling < state.size(); timeling++) {
        processSymbol(state[timeling]);
        int indexableX = round(location.x);
        int indexableY = round(location.y);
        Coordinate coordinate = {indexableX, indexableY};
        lattice.setColorIfValid(coordinate, soulColor);
    }
}

void Lindogram::advance(double distance) {
    auto deltaX = distance * cos(orientation);
    auto deltaY = distance * sin(orientation);
    auto newX = location.x + deltaX;
    auto newY = location.y + deltaY;
    location = {newX, newY};
}

void Lindogram::rotate(double radians) {
    orientation += radians;
}

void Lindogram::recurse() {
    std::vector<char> newState;
    for (auto symbol: state) {
        applyRules(newState, symbol);
    }
    state.clear();
    for (auto symbol: newState) {
        state.push_back(symbol);
    }
}

void Lindogram::tick() {
    currentTimeling++;
}

}
