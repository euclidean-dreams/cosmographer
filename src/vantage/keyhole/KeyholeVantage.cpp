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
    sendBuffer.push_back(AXIOM);
    sendBuffer.push_back(0);
    sendBuffer.push_back(0);
    sendBuffer.push_back(0);

    // led data
    for (int i = 0; i < glimpse->colors()->size(); i++) {
        auto color = glimpse->colors()->Get(i);
        sendBuffer.push_back(color->red());
        sendBuffer.push_back(color->green());
        sendBuffer.push_back(color->blue());
    }
    keyholeConnection->send(sendBuffer.data());

}

}
