#include "Config.h"

namespace cosmographer {

std::unique_ptr<Config> Config::instance = nullptr;

void Config::initialize() {
    if (instance == nullptr) {
        instance = std::unique_ptr<Config>(new Config());
    } else {
        throw std::logic_error("Attempted to initialize Config singleton more than once");
    }
}

Config &Config::getInstance() {
    return *instance;
}

Config::Config() {
    auto configFile = YAML::LoadFile(std::string{CONFIG_FILE_PATH});

    // general
    loggerName = configFile["general"]["loggerName"].as<std::string>();

    // socketry
    luciferonEndpoint = configFile["socketry"]["luciferon"].as<std::string>();
    palantirEndpoint = configFile["socketry"]["palantir"].as<std::string>();
    conductorEndpoint = configFile["socketry"]["conductor"].as<std::string>();
    fasciaEndpoint = configFile["socketry"]["fascia"].as<std::string>();

    // keyhole
    keyholeCount = configFile["keyhole"]["count"].as<uint>();
    keyholeWidth = configFile["keyhole"]["width"].as<uint>();
    keyholeHeight = configFile["keyhole"]["height"].as<uint>();
}

}
