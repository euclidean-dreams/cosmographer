#include "SPIConnection.h"
#include "pigpio.h"
#include "WaveletConstants.h"

namespace cosmographer {

SPIConnection::SPIConnection(sp<Arbiter<Lattice>> observation_arbiter)
        : sendBuffer{},
          observation_arbiter{mv(observation_arbiter)} {
    LOGGER->info("( ) spi connection");
    LOGGER->info("initializing pigpio");
    auto pigpioInitializationResult = gpioInitialise();
    if (pigpioInitializationResult < 0) {
        LOGGER->error("failed to initialize pigpio - failed with error code: {}", pigpioInitializationResult);
    }

    LOGGER->info("opening SPI connection");
    sendBuffer.resize(PACKET_SIZE, 0);
    spiHandle = spiOpen(0, BAUDRATE, 0);
    if (spiHandle < 0) {
        LOGGER->error("failed to open spi connection, error code: {}", spiHandle);
    }
    LOGGER->info("(*) spi connection");
}

void SPIConnection::send(const unsigned char *data) {
    std::memcpy(sendBuffer.data(), data, PACKET_SIZE);
    auto spiResult = spiWrite(spiHandle, sendBuffer.data(), PACKET_SIZE);
    if (spiResult != PACKET_SIZE) {
        LOGGER->info("spi write failed, error code: {}", spiResult);
    }
}

void SPIConnection::activate() {
    if (observation_arbiter->newDataAvailable()) {
        vec<unsigned char> sendBuffer;
        sendBuffer.reserve(PACKET_SIZE);

        // header
        sendBuffer.push_back(100);
        sendBuffer.push_back(0);
        sendBuffer.push_back(0);
        sendBuffer.push_back(0);

        auto lattice = observation_arbiter->take();
        for (int y = lattice->height - 1; y >= 0; y--) {
            for (int x = 0; x < lattice->width; x++) {
                auto color = lattice->getColor(x, y).convertToRGB();
                sendBuffer.push_back(color.red);
                sendBuffer.push_back(color.green);
                sendBuffer.push_back(color.blue);
            }
        }
        send(sendBuffer.data());
    }
}

uint64_t SPIConnection::getTickInterval() {
    return FRAME_RATE;
}

}
