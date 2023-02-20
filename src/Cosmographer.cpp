#include "Cosmographer.h"

#if VANTAGE == percipia

#include "vantage/PercipiaVantage.h"

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
#if VANTAGE == percipia
    auto percipiaSocket = mkup<NetworkSocket>(
            zmqContext,
            constants->percipiaEndpoint,
            zmq::socket_type::pub,
            true
    );
    subCommunity.vantage = mkup<PercipiaVantage>(mv(percipiaSocket));
#elif VANTAGE == keyhole
    subCommunity.vantage = mkup<KeyholeVantage>();
#elif VANTAGE == gubbin
#endif
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
    if (!receivedFirstEssentia) {
        LOGGER->info("received first essentia!");
        receivedFirstEssentia = true;
    }

    // refresh the paradigm
    volitiaParadigmBond->refresh();

    // handle new phenomena
    auto newPhenomenonParcels = subCommunity.phenomenology->take();
    for (auto &phenomenonParcel: *newPhenomenonParcels) {
        auto phenomenon = Unwrap::Phenomenon(*phenomenonParcel);
        auto identity = phenomenon->identity();
        LOGGER->info("received phenomenon! {}", identity);
        if (0 <= identity && identity < 5) {
            microMode = phenomenon->identity();
        } else if (100 <= identity && identity < 105) {
            macroMode = phenomenon->identity() - 100;
        } else if (200 <= identity && identity < 205) {
            chromatica->experiencePhenomenon(phenomenon);
        }
        if (identity == 1000) {
            LOGGER->info("((~)> current parameters:");
            LOGGER->info("((~)> 0: {}", axioms[0]);
            LOGGER->info("((~)> 1: {}", axioms[1]);
            LOGGER->info("((~)> 2: {}", axioms[2]);
            LOGGER->info("((~)> 3: {}", axioms[3]);
            LOGGER->info("((~)> 4: {}", axioms[4]);
            LOGGER->info("((~)> 5: {}", axioms[5]);
            LOGGER->info("((~)> 6: {}", axioms[6]);
            LOGGER->info("((~)> 7: {}", axioms[7]);
            LOGGER->info("((~)> 8: {}", axioms[8]);
            LOGGER->info("((~)> 9: {}", axioms[9]);
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
