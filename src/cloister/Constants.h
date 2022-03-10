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

    // sockets
    std::string palantirEndpoint = Config::getInstance().getString("palantirEndpoint");
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

    // mesh
    uint lumionCount = Config::getInstance().getUint("lumionCount");
    float lumionPlacement = Config::getInstance().getFloat("lumionPlacement");

    // ephemera
    int maxDriftDistance = 2;
    int maxGlimmerSpawnCount = 15;

    // illuminable
    float parametroTimelingIncrement = 0.05;

    // palette
    int maxHueJitter = 100;
    int maxFluxRequirement = 50 * 1000;
    int centrifugalPaletteFlux = 100000;
    int minimumBeatInterval = 100 * 1000;
    uint movingAverageSize = 100;

    // TODO finish transition
};

}

#endif //COSMOGRAPHER_CONSTANTS_H
