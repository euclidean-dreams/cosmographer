#ifndef COSMOGRAPHER_KEYHOLECONNECTION_H
#define COSMOGRAPHER_KEYHOLECONNECTION_H

#include "Default.h"

namespace cosmographer {

class KeyholeConnection {
private:
    std::vector<char> sendBuffer;
    int spiHandle;
    int baudRate = 5 * 1000 * 1000;

public:
    KeyholeConnection();

    void send(const unsigned char *data);
};

}

}

#endif //COSMOGRAPHER_KEYHOLECONNECTION_H
