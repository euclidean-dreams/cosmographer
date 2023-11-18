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
        if (0 <= identity && identity < 100) {
            microMode = phenomenon->identity();
        } else if (100 <= identity && identity < 200) {
            macroMode = phenomenon->identity() - 100;
        } else if (200 <= identity && identity < 205) {
            chromatica->experiencePhenomenon(phenomenon);
        }
        if (identity == 1000) {
            LOGGER->info("((~)> current parameters:");
            LOGGER->info("((~)> COSMOLOGY_SIZE: {}", COSMOLOGY_SIZE_AXIOM);
            LOGGER->info("((~)> PLACEMENT: {}", PLACEMENT_AXIOM);
            LOGGER->info("((~)> EXCITATION: {}", EXCITATION_AXIOM);
            LOGGER->info("((~)> EXHAUSTION: {}", EXHAUSTION_AXIOM);
            LOGGER->info("((~)> MAGNITUDE: {}", MAGNITUDE_AXIOM);
            LOGGER->info("((~)> CHANGE: {}", CHANGE_AXIOM);
            LOGGER->info("((~)> CHAOS: {}", CHAOS_AXIOM);
            LOGGER->info("((~)> GROWTH: {}", GROWTH_AXIOM);
            LOGGER->info("((~)> OSCILLATION: {}", OSCILLATION_AXIOM);
            LOGGER->info("((~)> COLOR_BASE: {}", COLOR_BASE_AXIOM);
            LOGGER->info("((~)> COLOR_ACCENT: {}", COLOR_ACCENT_AXIOM);
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
