#ifndef COSMOGRAPHER_SPICONNECTION_H
#define COSMOGRAPHER_SPICONNECTION_H

#include "Default.h"
#include "primitive/Lattice.h"

namespace cosmographer {

class SPIConnection : public TickingCirculable {
private:
    std::vector<char> sendBuffer;
    int spiHandle;
    sp<Arbiter<Lattice>> observation_arbiter;

    void send(const unsigned char *data);

public:
    SPIConnection(sp<Arbiter<Lattice>> observation_arbiter);

    void activate() override;

    uint64_t getTickInterval() override;
};

}

#endif //COSMOGRAPHER_SPICONNECTION_H
