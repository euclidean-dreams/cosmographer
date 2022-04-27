#include "KeyholeConnection.h"
#include "KeyholeConstants.h"
#include <pigpio.h>

namespace cosmographer {

KeyholeConnection::KeyholeConnection()
        : sendBuffer{} {
    LOGGER->info("initializing pigpio");
    auto pigpioInitializationResult = gpioInitialise();
    if (pigpioInitializationResult < 0) {
        LOGGER->error("failed to initialize pigpio - failed with error code: {}", pigpioInitializationResult);
    }

    LOGGER->info("initializing keyhole vantage");
    sendBuffer.resize(PACKET_SIZE, 0);
    spiHandle = spiOpen(0, BAUDRATE, 0);
    if (spiHandle < 0) {
        LOGGER->error("failed to open spi connection, error code: {}", spiHandle);
    }
}

void KeyholeConnection::send(const unsigned char *data) {
    std::memcpy(sendBuffer.data(), data, PACKET_SIZE);
    auto spiResult = spiWrite(spiHandle, sendBuffer.data(), PACKET_SIZE);
    if (spiResult != PACKET_SIZE) {
        LOGGER->info("spi write failed, error code: {}", spiResult);
    }
}

}
