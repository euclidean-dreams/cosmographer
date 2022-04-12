#ifndef COSMOGRAPHER_ANTECHAMBER_H
#define COSMOGRAPHER_ANTECHAMBER_H

#include <condition_variable>
#include "Default.h"

namespace cosmographer {

class Antechamber {
public:
    std::mutex mutex;
    std::condition_variable notifier;
    int targetLoungerCount;
    int currentLoungerCount;

    Antechamber(
            int targetLoungerCount
    );

    void lounge();

    void clean();
};

}

#endif //COSMOGRAPHER_ANTECHAMBER_H
