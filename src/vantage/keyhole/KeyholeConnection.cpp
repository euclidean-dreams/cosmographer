#include "KeyholeConnection.h"
#include <pigpio.h>

namespace cosmographer {

KeyholeConnection::KeyholeConnection()
        : sendBuffer{} {
    LOGGER->info("initializing keyhole connection");
    sendBuffer.resize(packetSize, 0);
    spiHandle = spiOpen(0, baudRate, 0);
    if (spiHandle < 0) {
        LOGGER->error("failed to open spi connection, error code: {}", spiHandle);
    }
}

void KeyholeConnection::send(const unsigned char *data) {
    std::memcpy(sendBuffer.data(), data, packetSize);
    auto spiResult = spiWrite(spiHandle, sendBuffer.data(), packetSize);
    if (spiResult != packetSize) {
        spdlog::get(LOGGER_NAME)->info("spi write failed, error code: {}", spiResult);
    }
}

}
