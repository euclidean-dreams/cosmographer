#ifndef COSMOGRAPHER_KEYHOLECONNECTION_H
#define COSMOGRAPHER_KEYHOLECONNECTION_H

#include "Default.h"

namespace cosmographer {

class KeyholeConnection {
private:
    std::vector<char> sendBuffer;
    int spiHandle;

public:
    KeyholeConnection();

    void send(const unsigned char *data);
};

}

#endif //COSMOGRAPHER_KEYHOLECONNECTION_H
