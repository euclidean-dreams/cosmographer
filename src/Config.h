#ifndef COSMOGRAPHER_CONFIG_H
#define COSMOGRAPHER_CONFIG_H

// general
#define VANTAGE_TYPE impresarioUtils::Config::getInstance().getInt("vantage_type")

// tick interval
#define LUCIFERON_TICK_INTERVAL impresarioUtils::Config::getInstance().getInt("luciferon_tick_interval")

// socketry
#define LUCIFERON_ENDPOINT impresarioUtils::Config::getInstance().getString("luciferon_endpoint")
#define PALANTIR_ENDPOINT impresarioUtils::Config::getInstance().getString("palantir_endpoint")
#define ANALOGORIUM_ENDPOINT impresarioUtils::Config::getInstance().getString("analogorium_endpoint")
#define VOLITIA_ENDPOINT impresarioUtils::Config::getInstance().getString("volitia_endpoint")

// lattice
#define LATTICE_WIDTH impresarioUtils::Config::getInstance().getUint("lattice_width")
#define LATTICE_HEIGHT impresarioUtils::Config::getInstance().getUint("lattice_height")

#endif //COSMOGRAPHER_CONFIG_H
