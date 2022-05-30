#ifndef COSMOGRAPHER_POLE_H
#define COSMOGRAPHER_POLE_H

namespace cosmographer {

class Pole {
public:
    float pole;
    bool deltaDirection;

    Pole();

    void refresh();
};

}

#endif //COSMOGRAPHER_POLE_H
