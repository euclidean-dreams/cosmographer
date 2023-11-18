#include "WaveletVantage.h"
#include "SPIConnection.h"


namespace cosmographer {

WaveletVantage::WaveletVantage(

) :
        observation_arbiter{} {
    LOGGER->info("( ) wavelet vantage");
    observation_arbiter = mksp<Arbiter<Lattice>>();
    auto waveletConnection = mkup<SPIConnection>(observation_arbiter);
    waveletConnectionThread = Circlet::begin(mv(waveletConnection));
    LOGGER->info("(*) wavelet vantage");
}

void WaveletVantage::send(up<Lattice> lattice) {
    observation_arbiter->give(mv(lattice));
}

}
