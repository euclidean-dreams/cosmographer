#include "Default.h"
#include "Cosmographer.h"
#include "cloister/Constants.h"

namespace cosmographer {

up<Paradigm> paradigmWrapper = mkup<Paradigm>();
Paradigm *paradigm = paradigmWrapper.get();

int bootstrap() {
    std::string configFilePath = "./config.yml";
    Bootstrapper bootstrapper(configFilePath, 1);

    // arbiters
    auto axiomArbiter = mksp<Arbiter<const Parcel>>();
    auto phenomenology = mksp<BufferArbiter<const Parcel>>();

    // cloister
    CLOISTER = mkup<CloisterCommunity>();
    CONSTANTS = mkup<Constants>();
    CONSTANTS->initialize(CLOISTER.get());
    CLOISTER->axiomRefresher = mkup<AxiomRefresher>(axiomArbiter);
    CLOISTER->axiomRefresher->initialize(CLOISTER.get());
    CLOISTER->randomizer = mkup<Randomizer>();
    CLOISTER->randomizer->initialize(CLOISTER.get());
    CLOISTER->cartographer = mkup<Cartographer>();
    CLOISTER->cartographer->initialize(CLOISTER.get());
    CLOISTER->chromatica = mkup<Chromatica>(CLOISTER.get());
    CLOISTER->chromatica->initialize(CLOISTER.get());
    CLOISTER->colorPixie = mkup<ColorPixie>();
    CLOISTER->colorPixie->initialize(CLOISTER.get());
    CLOISTER->signalarium = mkup<Signalarium>();
    CLOISTER->signalarium->initialize(CLOISTER.get());

    // extras
    paradigm->axioms.resize(CONSTANTS->axiomologySize, 0.5);
    paradigm->microMode = 0;
    paradigm->macroMode = 0;

    // percipient
    auto volitiaPercipientThread = VolitiaPercipient::create(
            bootstrapper.getZmqContext(),
            CONSTANTS->volitiaEndpoint,
            axiomArbiter,
            phenomenology
    );

    // cosmographer
    auto cosmographer = mkup<Cosmographer>(
            bootstrapper.getZmqContext(),
            paradigm,
            mv(phenomenology)
    );
    auto cosmographerThread = Circlet::begin(mv(cosmographer));

    // go time!
    cosmographerThread->join();
    volitiaPercipientThread->join();

    return 0;
}

}

int main() {
    return cosmographer::bootstrap();
}
