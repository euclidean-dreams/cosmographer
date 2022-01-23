#ifndef COSMOGRAPHER_SIGNAL_H
#define COSMOGRAPHER_SIGNAL_H

#include "cosmology/illuminable/Illuminable.h"

namespace cosmographer {

class Signal : public Illuminable {
private:
    std::vector<float> samples;

public:
    Signal(Coordinate origin, HSLColor soulColor, std::vector<float> samples);

    void illuminate(Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_SIGNAL_H
