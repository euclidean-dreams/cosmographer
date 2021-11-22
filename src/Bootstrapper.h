#ifndef COSMOGRAPHER_BOOTSTRAPPER_H
#define COSMOGRAPHER_BOOTSTRAPPER_H

#include <ImpresarioUtils.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "Config.h"
#include "Cosmographer.h"
#include "vantage/LuciferonVantage.h"
#include "vantage/PalantirVantage.h"

namespace cosmographer {

class Bootstrapper : public impresarioUtils::NonCopyable {
public:
    static void boot();
};

}

#endif //COSMOGRAPHER_BOOTSTRAPPER_H
