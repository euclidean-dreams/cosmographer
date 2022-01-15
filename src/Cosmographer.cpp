#include "Cosmographer.h"

namespace cosmographer {

Cosmographer::Cosmographer(std::unique_ptr<Vantage> vantage,
                           std::unique_ptr<impresarioUtils::NetworkSocket> essentiaSocket,
                           std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology)
        : vantage{move(vantage)},
          essentiaSocket{move(essentiaSocket)},
          phenomenology{move(phenomenology)},
          cosmology{std::make_shared<Cosmology>()} {

}

void Cosmographer::activate() {
    // wait for a new essentia
    auto essentiaParcelBundle = receiveEssentiaParcelBundle();

    // refresh the paradigm
    PARADIGM.refresh();

    // handle new phenomena
    auto newPhenomenonParcels = phenomenology->take();
    for (auto &phenomenonParcel: *newPhenomenonParcels) {
        auto phenomenon = impresarioUtils::Unwrap::Phenomenon(*phenomenonParcel);
        cosmology->experiencePhenomenon(phenomenon);
    }

    // experience the essentia
    for (auto &essentiaParcel: essentiaParcelBundle) {
        auto essentia = impresarioUtils::Unwrap::Essentia(*essentiaParcel);
        cosmology->experienceEssentia(essentia);
    }


    // generate lattice and send frame
    auto lattice = cosmology->observe();
    vantage->send(*lattice);
}

std::vector<std::unique_ptr<impresarioUtils::Parcel>> Cosmographer::receiveEssentiaParcelBundle() {
    std::vector<std::unique_ptr<impresarioUtils::Parcel>> bundle{};
    bundle.push_back(essentiaSocket->receiveParcel());
    auto essentia = essentiaSocket->receiveParcel(zmq::recv_flags::dontwait);
    while (essentia != nullptr) {
        bundle.push_back(move(essentia));
        essentia = essentiaSocket->receiveParcel(zmq::recv_flags::dontwait);
    }
    return bundle;
}

bool Cosmographer::finished() {
    return false;
}

}
