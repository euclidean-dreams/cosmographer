#include "Loci.h"

namespace cosmographer {

uint percipiaWidth;

void initializeCoordinateHash() {
    percipiaWidth = Config::getInstance().getUint("percipiaWidth");
}

size_t CoordinateHash::operator()(const Coordinate &locus) const {
    return locus.y * percipiaWidth + locus.x;
}

}
