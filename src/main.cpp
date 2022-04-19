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
    paradigm->cloister = mkup<CloisterCommunity>();
    paradigm->cloister->constants = mkup<Constants>();
    paradigm->cloister->constants->initialize(paradigm->cloister.get());
    paradigm->cloister->axiomRefresher = mkup<AxiomRefresher>(axiomArbiter);
    paradigm->cloister->axiomRefresher->initialize(paradigm->cloister.get());
    paradigm->cloister->randomizer = mkup<Randomizer>();
    paradigm->cloister->randomizer->initialize(paradigm->cloister.get());
    paradigm->cloister->cartographer = mkup<Cartographer>();
    paradigm->cloister->cartographer->initialize(paradigm->cloister.get());
    paradigm->cloister->chromatica = mkup<Chromatica>(paradigm->cloister.get());
    paradigm->cloister->chromatica->initialize(paradigm->cloister.get());
    paradigm->cloister->colorPixie = mkup<ColorPixie>();
    paradigm->cloister->colorPixie->initialize(paradigm->cloister.get());

    // extras
    paradigm->axioms.resize(paradigm->cloister->constants->axiomologySize, 0.5);
    paradigm->microMode = 0;
    paradigm->macroMode = 0;

    // percipient
    auto volitiaPercipientThread = VolitiaPercipient::create(
            bootstrapper.getZmqContext(),
            paradigm->cloister->constants->volitiaEndpoint,
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
