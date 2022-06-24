#include "Cosmographer.h"
#include "vantage/Vantage.h"


namespace cosmographer {

Cosmographer::Cosmographer(
        zmq::context_t &zmqContext,
        Paradigm *paradigm,
        sp<BufferArbiter<const Parcel>> phenomenology
) :
        Liaison<CosmographerCommunity>(paradigm) {
    subCommunity.cosmology = mkup<Cosmology>(&subCommunity);
    subCommunity.cosmology->initialize(&subCommunity);
    subCommunity.phenomenology = mv(phenomenology);

    auto vantageSocket = mkup<NetworkSocket>(
            zmqContext,
            constants->percipiaEndpoint,
            zmq::socket_type::pub,
            true
    );
    subCommunity.vantage = mkup<Vantage>(mv(vantageSocket));
    subCommunity.vantage->initialize(&subCommunity);

    // cosmographer
    subCommunity.essentiaSocket = mkup<NetworkSocket>(
            zmqContext,
            constants->essentiaEndpoint,
            zmq::socket_type::sub,
            false
    );
    subCommunity.essentiaSocket->setSubscriptionFilter(Identifier::essentia);
}

void Cosmographer::activate() {
    // wait for a new essentia
    auto essentiaParcelBundle = receiveEssentiaParcelBundle();
    if(!receivedFirstEssentia) {
        LOGGER->info("received first essentia!");
        receivedFirstEssentia = true;
    }

    // refresh the paradigm
    volitiaParadigmBond->refresh();

    // handle new phenomena
    auto newPhenomenonParcels = subCommunity.phenomenology->take();
    for (auto &phenomenonParcel: *newPhenomenonParcels) {
        if(!receivedFirstPhenomenon) {
            LOGGER->info("received first phenomenon!");
            receivedFirstPhenomenon = true;
        }
        auto phenomenon = Unwrap::Phenomenon(*phenomenonParcel);
        auto button = phenomenon->identity();
        if (button < 5) {
            chromatica->experiencePhenomenon(phenomenon);
        }
        if (button >= 5 && button < 8) {
            macroMode = phenomenon->identity() - 5;
        }
        if (button == 8) {
            centerMode = !centerMode;
        }
    }

    // experience the essentia
    for (auto &essentiaParcel: essentiaParcelBundle) {
        signalarium->refresh(mv(essentiaParcel));
        chromatica->experienceEssentia();
        subCommunity.cosmology->experienceEssentia();
        pole->refresh();
        volitiaGolem->refresh();
        lumionBookie->clear();
    }

    // todo find a better place for this

    // generate lattice and send frame
    subCommunity.cosmology->observe();
}

vec<up<Parcel>> Cosmographer::receiveEssentiaParcelBundle() {
    vec<up<Parcel>> bundle{};
    bundle.push_back(subCommunity.essentiaSocket->receiveParcel());
    auto essentia = subCommunity.essentiaSocket->receiveParcel(zmq::recv_flags::dontwait);
    while (essentia != nullptr) {
        bundle.push_back(mv(essentia));
        essentia = subCommunity.essentiaSocket->receiveParcel(zmq::recv_flags::dontwait);
    }
    return bundle;
}

}
