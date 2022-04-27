#ifndef COSMOGRAPHER_KEYHOLEVANTAGE_H
#define COSMOGRAPHER_KEYHOLEVANTAGE_H

#include "vantage/Vantage.h"
#include "KeyholeConnection.h"

namespace cosmographer {

class KeyholeVantage : public Vantage {
public:
    KeyholeConnection keyholeConnection;

    KeyholeVantage(

    );

    void send(const Lattice &lattice) override;
};

}

#endif //COSMOGRAPHER_KEYHOLEVANTAGE_H
