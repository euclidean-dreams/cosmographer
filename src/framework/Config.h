#ifndef COSMOGRAPHER_CONFIG_H
#define COSMOGRAPHER_CONFIG_H

// axiom bindings
#define AXIOM(index) community->paradigm->axioms[index]
#define PALETTE_AXIOM_0 AXIOM(0)
#define PALETTE_AXIOM_1 AXIOM(1)
#define LUMION_EXCITATION_AXIOM AXIOM(2)
#define GLIMMER_SIZE_AXIOM AXIOM(3)
#define GLIMMER_COUNT_AXIOM AXIOM(4)
#define EPHEMERA_AXIOM_0 AXIOM(5)
#define EPHEMERA_AXIOM_1 AXIOM(6)
#define EPHEMERA_AXIOM_2 AXIOM(7)
#define HUE_JITTER_AXIOM AXIOM(9)

// ephemera
#define MAX_DRIFT_DISTANCE 10
#define MAX_GLIMMER_COUNT 15

// illuminable
#define PARAMETRO_TIMELING_INCREMENT 0.05

// palette
#define MAX_HUE_JITTER 100
#define MAX_FLUX_REQUIREMENT (50 * 1000)
#define MINIMUM_BEAT_INTERVAL (100 * 1000)
#define MOVING_AVERAGE_SIZE 100

// general
#define VANTAGE_TYPE Config::getInstance().getInt("vantage_type")
#define AXIOMOLOGY_SIZE Config::getInstance().getUint("axiomology_size")

// tick interval
#define LUCIFERON_TICK_INTERVAL Config::getInstance().getInt("luciferon_tick_interval")

// socketry
#define LUCIFERON_ENDPOINT Config::getInstance().getString("luciferon_endpoint")
#define PALANTIR_ENDPOINT Config::getInstance().getString("palantir_endpoint")
#define ANALOGORIUM_ENDPOINT Config::getInstance().getString("analogorium_endpoint")
#define VOLITIA_ENDPOINT Config::getInstance().getString("volitia_endpoint")

// lattice
#define LATTICE_WIDTH Config::getInstance().getUint("lattice_width")
#define LATTICE_HEIGHT Config::getInstance().getUint("lattice_height")
#define LATTICE_INITIAL_HUE Config::getInstance().getInt("lattice_initial_hue")
#define LATTICE_INITIAL_SATURATION Config::getInstance().getInt("lattice_initial_saturation")
#define LATTICE_INITIAL_LIGHTNESS Config::getInstance().getInt("lattice_initial_lightness")

// mesh
#define LUMION_COUNT Config::getInstance().getUint("lumion_count")

#endif //COSMOGRAPHER_CONFIG_H
