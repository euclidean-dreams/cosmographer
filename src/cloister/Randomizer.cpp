#include "Randomizer.h"
#include "Default.h"

namespace cosmographer {

int Randomizer::generate(int exclusive_max) {
    return generateNumber(exclusive_max);
}

float Randomizer::generateProportion() {
    return cast(float, generateNumber(10000)) / 9999;
}

int Randomizer::generateNumber(int exclusive_max) {
    if (exclusive_max <= 0) {
        return 0;
    }
    return cast(int, community->signalarium->stft.energy * 100000) % exclusive_max;
}
}
