#ifndef COSMOGRAPHER_CONSTANTS_H
#define COSMOGRAPHER_CONSTANTS_H

#include "CloisterCommunity.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class Constants : public Fellow<CloisterCommunity> {
public:
    // general
    uint axiomologySize = Config::getInstance().getUint("axiomologySize");
    int maxGlimmers = Config::getInstance().getInt("maxGlimmers");
    int illuminatorThreadCount = Config::getInstance().getInt("illuminatorThreadCount");
    uint lumionCount = Config::getInstance().getUint("lumionCount");

    // endpoints
    std::string percipiaEndpoint = Config::getInstance().getString("percipiaEndpoint");
    std::string essentiaEndpoint = Config::getInstance().getString("essentiaEndpoint");
    std::string volitiaEndpoint = Config::getInstance().getString("volitiaEndpoint");

    // lattice
    uint latticeWidth = Config::getInstance().getUint("latticeWidth");
    uint latticeHeight = Config::getInstance().getUint("latticeHeight");
    HSLColor latticeInitialColor = HSLColor{
            Config::getInstance().getInt("latticeInitialHue"),
            Config::getInstance().getInt("latticeInitialSaturation"),
            Config::getInstance().getInt("latticeInitialLightness"),
    };

    // ephemera
    int maxLifespan = 300;
    int maxGlimmerSpawnCount = 8;

    // palette
    int maxFluxRequirement = 100 * 1000;
    int centrifugalPaletteFlux = 10;
    int minimumBeatInterval = 100 * 1000;
    uint movingAverageSize = 100;
};

}

#endif //COSMOGRAPHER_CONSTANTS_H
