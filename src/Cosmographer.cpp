#include "Cosmographer.h"

#if VANTAGE == palantir

#include "vantage/PalantirVantage.h"

#endif
#if VANTAGE == keyhole

#include "vantage/keyhole/KeyholeVantage.h"

#endif
#if VANTAGE == gubbin

#endif

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
#if VANTAGE == palantir
    auto palantirSocket = mkup<NetworkSocket>(
            zmqContext,
            CONSTANTS->palantirEndpoint,
            zmq::socket_type::pub,
            true
    );
    subCommunity.vantage = mkup<PalantirVantage>(mv(palantirSocket));
#elif VANTAGE == keyhole
    subCommunity.vantage = mkup<KeyholeVantage>();
#elif VANTAGE == gubbin
#endif
    subCommunity.vantage->initialize(&subCommunity);

    // cosmographer
    subCommunity.essentiaSocket = mkup<NetworkSocket>(
            zmqContext,
            CONSTANTS->essentiaEndpoint,
            zmq::socket_type::sub,
            false
    );
    subCommunity.essentiaSocket->setSubscriptionFilter(Identifier::essentia);
}

void Cosmographer::activate() {
    // wait for a new essentia
    auto essentiaParcelBundle = receiveEssentiaParcelBundle();

    // refresh the paradigm
    CLOISTER->axiomRefresher->refresh();

    // handle new phenomena
    auto newPhenomenonParcels = subCommunity.phenomenology->take();
    for (auto &phenomenonParcel: *newPhenomenonParcels) {
        auto phenomenon = Unwrap::Phenomenon(*phenomenonParcel);
        auto button = phenomenon->identity();
//        if (button < 5) {
//            CLOISTER->chromatica->experiencePhenomenon(phenomenon);
//        } else if (button < 10) {
//            paradigm->mode = phenomenon->identity() - 5;
//        }
        if (button < 5) {
            paradigm->microMode = phenomenon->identity();
        } else if (button < 10) {
            paradigm->macroMode = phenomenon->identity() - 5;
        }
    }

    // experience the essentia
    for (auto &essentiaParcel: essentiaParcelBundle) {
        auto essentia = Unwrap::Essentia(*essentiaParcel);
        CLOISTER->chromatica->experienceEssentia(essentia);
        subCommunity.cosmology->experienceEssentia(essentia);
    }

    // todo find a better place for this
//    CONSTANTS.

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
