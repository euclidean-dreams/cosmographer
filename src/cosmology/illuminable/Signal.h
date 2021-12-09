#ifndef COSMOGRAPHER_SIGNAL_H
#define COSMOGRAPHER_SIGNAL_H

#include "cosmology/illuminable/Illuminable.h"

namespace cosmographer {

class Signal : public Illuminable {
private:
    std::vector<float> signal;

public:
    Signal(HSLColor soulColor, std::vector<float> signal);

    void illuminate(Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_SIGNAL_H
