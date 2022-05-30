#ifndef COSMOGRAPHER_CONSTANTS_H
#define COSMOGRAPHER_CONSTANTS_H

#include "primitive/color/HSLColor.h"

namespace cosmographer {

class Constants {
public:
    // general
    uint axiomologySize = Config::getInstance().getUint("axiomologySize");
    int maxGlimmers = Config::getInstance().getInt("maxGlimmers");
    int illuminatorThreadCount = std::thread::hardware_concurrency();
    uint lumionCount = Config::getInstance().getUint("lumionCount");

    // endpoints
    std::string percipiaEndpoint = Config::getInstance().getString("percipiaEndpoint");
    std::string essentiaEndpoint = Config::getInstance().getString("essentiaEndpoint");
    std::string volitiaEndpoint = Config::getInstance().getString("volitiaEndpoint");

    // lattice
    uint percipiaWidth = Config::getInstance().getUint("percipiaWidth");
    uint percipiaHeight = Config::getInstance().getUint("percipiaHeight");
    HSLColor latticeInitialColor = HSLColor{
            Config::getInstance().getInt("latticeInitialHue"),
            Config::getInstance().getInt("latticeInitialSaturation"),
            Config::getInstance().getInt("latticeInitialLightness"),
    };

    // ephemera
    int maxLifespan = 300;
    int glimmerSpawnCountScaler = 8;

    // palette
    int maxFluxRequirement = 100 * 1000;
    int centrifugalPaletteFlux = 1000;
    int minimumBeatInterval = 100 * 1000;
    uint signalAverageSize = 1000;

    float baseGlimmerSize = Config::getInstance().getFloat("baseGlimmerSize");
};

}

#endif //COSMOGRAPHER_CONSTANTS_H
