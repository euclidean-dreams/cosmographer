#include "Tidbit.h"

namespace cosmographer {

float Tidbit::bind(
        float value,
        float min,
        float max
) {
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}

int Tidbit::bind(
        int value,
        int min,
        int max
) {
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}

float Tidbit::collapse(
        float value,
        float max
) {
    while (value > max) {
        value -= max;
    }
    while (value < 0) {
        value += max;
    }
    return value;
}

}
