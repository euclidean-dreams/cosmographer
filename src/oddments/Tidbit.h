#ifndef COSMOGRAPHER_TIDBIT_H
#define COSMOGRAPHER_TIDBIT_H

namespace cosmographer {

class Tidbit {
public:
    static float bind(float value, float min, float max);

    static int bind(int value, int min, int max);

    static float collapse(float value, float max);
};

}

#endif //COSMOGRAPHER_TIDBIT_H
