#ifndef COSMOGRAPHER_KEYHOLEVANTAGE_H
#define COSMOGRAPHER_KEYHOLEVANTAGE_H

#include "vantage/Vantage.h"
#include "SPIConnection.h"

namespace cosmographer {

class WaveletVantage : public Vantage {
private:
    sp<Arbiter<Lattice>> observation_arbiter;
    up<std::thread> waveletConnectionThread;


public:
    WaveletVantage();

    void send(up<Lattice> lattice) override;

};

}

#endif //COSMOGRAPHER_KEYHOLEVANTAGE_H
