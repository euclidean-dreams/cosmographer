#include "Antechamber.h"

namespace cosmographer {

Antechamber::Antechamber(
        int targetLoungerCount
) :
        mutex{},
        notifier{},
        targetLoungerCount{targetLoungerCount},
        currentLoungerCount{0} {

}

void Antechamber::lounge() {
    std::unique_lock<std::mutex> lock{mutex};
    currentLoungerCount++;
    if (currentLoungerCount == targetLoungerCount) {
        notifier.notify_all();
    } else {
        notifier.wait(lock);
    }
}

void Antechamber::clean() {
    currentLoungerCount = 0;
}

}
