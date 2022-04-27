#include "KeyholeVantage.h"
#include "KeyholeConstants.h"

namespace cosmographer {

KeyholeVantage::KeyholeVantage(

) :
        keyholeConnection{} {

}

void KeyholeVantage::send(const Lattice &lattice) {
    std::vector<unsigned char> sendBuffer;
    sendBuffer.reserve(PACKET_SIZE);

    // header
    sendBuffer.push_back(100 * BRIGHTNESS_AXIOM);
    sendBuffer.push_back(0);
    sendBuffer.push_back(0);
    sendBuffer.push_back(0);

    for (int x = 0; x < lattice.width; x++) {
        if (x % 2 == 0) {
            for (int y = 0; y < lattice.height; y++) {
                auto color = lattice.getColor(x, y).convertToRGB();
                sendBuffer.push_back(color.red);
                sendBuffer.push_back(color.green);
                sendBuffer.push_back(color.blue);
            }
        } else {
            for (int y = lattice.height - 1; y >= 0; y--) {
                auto color = lattice.getColor(x, y).convertToRGB();
                sendBuffer.push_back(color.red);
                sendBuffer.push_back(color.green);
                sendBuffer.push_back(color.blue);
            }
        }
    }
    keyholeConnection.send(sendBuffer.data());
}

}
