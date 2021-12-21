#ifndef COSMOGRAPHER_DRAGONCURVE_H
#define COSMOGRAPHER_DRAGONCURVE_H

#include "cosmology/illuminable/lindogram/Lindogram.h"

namespace cosmographer {

class DragonCurve : public Lindogram {
private:
    double scale;

protected:
    void applyRules(std::vector<char> &newState, char symbol) override;

    void processSymbol(char symbol) override;

public:
    DragonCurve(Coordinate origin, HSLColor soulColor, double orientation, int recursions, double scale);
};

}

#endif //COSMOGRAPHER_DRAGONCURVE_H
