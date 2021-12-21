#ifndef COSMOGRAPHER_LINDOGRAM_H
#define COSMOGRAPHER_LINDOGRAM_H

#include "cosmology/illuminable/Illuminable.h"
#include "gizmo/Point.h"

namespace cosmographer {

class Lindogram : public Illuminable {
protected:
    Point location;
    double initialOrientation;
    double orientation;
    std::vector<char> state;
    int currentTimeling;

    virtual void applyRules(std::vector<char> &newState, char symbol) = 0;

    virtual void processSymbol(char symbol) = 0;

    void advance(double distance);

    void rotate(double radians);

public:
    Lindogram(Coordinate origin, HSLColor soulColor, double orientation);

    void illuminate(Lattice &lattice) override;

    void recurse();

    void tick();
};

}

#endif //COSMOGRAPHER_LINDOGRAM_H
