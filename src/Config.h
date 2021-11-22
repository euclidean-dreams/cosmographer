#ifndef COSMOGRAPHER_CONFIG_H
#define COSMOGRAPHER_CONFIG_H

#include <memory>
#include <stdexcept>
#include <yaml-cpp/yaml.h>
#include <ImpresarioUtils.h>

namespace cosmographer {

class Config {
private:
    static constexpr std::string_view CONFIG_FILE_PATH = "./config.yml";
    static std::unique_ptr<Config> instance;

    // general
    std::string loggerName;

    // socketry
    std::string luciferonEndpoint;
    std::string palantirEndpoint;
    std::string conductorEndpoint;
    std::string fasciaEndpoint;

    // keyhole
    uint keyholeCount;
    uint keyholeWidth;
    uint keyholeHeight;

    Config();

public:
    static Config &getInstance();

    static void initialize();

    // general
    std::string getLoggerName() const { return loggerName; }

    // socketry
    std::string getLuciferonEndpoint() const { return luciferonEndpoint; }

    std::string getPalantirEndpoint() const { return palantirEndpoint; }

    std::string getConductorEndpoint() const { return conductorEndpoint; }

    std::string getFasciaEndpoint() const { return fasciaEndpoint; }

    // keyhole
    uint getKeyholeCount() const { return keyholeCount; }

    uint getKeyholeWidth() const { return keyholeWidth; }

    uint getKeyholeHeight() const { return keyholeHeight; }
};

}

#endif //COSMOGRAPHER_CONFIG_H
