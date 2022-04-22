#ifndef COSMOGRAPHER_KEYHOLEVANTAGE_H
#define COSMOGRAPHER_KEYHOLEVANTAGE_H

#include "vantage/Vantage.h"
#include "KeyholeConnection.h"

namespace cosmographer {

class KeyholeVantage : public Vantage {
public:
    int headerSize = 4;
    int ledCount = 74 * 20;
    int packetSize = headerSize + ledCount * 3;

    KeyholeConnection keyholeConnection;

    KeyholeVantage(

    );

    void send(const Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_KEYHOLEVANTAGE_H
