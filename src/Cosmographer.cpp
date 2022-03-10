#include "Cosmographer.h"

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

    // vantage
    auto palantirSocket = mkup<NetworkSocket>(
            zmqContext,
            paradigm->cloister->constants->palantirEndpoint,
            zmq::socket_type::pub,
            true
    );
    subCommunity.vantage = mkup<PalantirVantage>(mv(palantirSocket));
    subCommunity.vantage->initialize(&subCommunity);

    // cosmographer
    subCommunity.essentiaSocket = mkup<NetworkSocket>(
            zmqContext,
            paradigm->cloister->constants->essentiaEndpoint,
            zmq::socket_type::sub,
            false
    );
    subCommunity.essentiaSocket->setSubscriptionFilter(Identifier::essentia);
}

void Cosmographer::activate() {
    // wait for a new essentia
    auto essentiaParcelBundle = receiveEssentiaParcelBundle();

    // refresh the paradigm
    subCommunity.paradigm->cloister->axiomRefresher->refresh();

    // handle new phenomena
    auto newPhenomenonParcels = subCommunity.phenomenology->take();
    for (auto &phenomenonParcel: *newPhenomenonParcels) {
        auto phenomenon = Unwrap::Phenomenon(*phenomenonParcel);
        auto button = phenomenon->identity();
        if (button < 5) {
            subCommunity.paradigm->cloister->chromatica->experiencePhenomenon(phenomenon);
        } else if (button < 10) {
            subCommunity.paradigm->mode = phenomenon->identity() - 5;
        }
    }

    // experience the essentia
    for (auto &essentiaParcel: essentiaParcelBundle) {
        auto essentia = Unwrap::Essentia(*essentiaParcel);
        subCommunity.paradigm->cloister->chromatica->experienceEssentia(essentia);
        subCommunity.cosmology->experienceEssentia(essentia);
    }

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
