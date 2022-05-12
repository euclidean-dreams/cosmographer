#include "Default.h"
#include "Cosmographer.h"
#include "cloister/Constants.h"

namespace cosmographer {

up<Paradigm> paradigmWrapper = mkup<Paradigm>();
Paradigm *paradigm = paradigmWrapper.get();

int bootstrap(std::string configFilePath) {
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
    CLOISTER->volitiaGolem = mkup<VolitiaGolem>();
    CLOISTER->volitiaGolem->initialize(CLOISTER.get());
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
    CLOISTER->pole = mkup<Pole>();
    CLOISTER->pole->initialize(CLOISTER.get());
    CLOISTER->lumionBookie = mkup<LumionBookie>();
    CLOISTER->lumionBookie->initialize(CLOISTER.get());

    // extras
    paradigm->axioms.push_back(0.3);
    paradigm->axioms.push_back(0.1);
    paradigm->axioms.push_back(1.0);
    paradigm->axioms.push_back(0.4);
    paradigm->axioms.push_back(0.3);
    paradigm->axioms.push_back(0.7);
    paradigm->axioms.push_back(0.2);
    paradigm->axioms.push_back(0.2);
    paradigm->axioms.push_back(0.5);
    paradigm->axioms.push_back(0.5);
    paradigm->microMode = 0;
    paradigm->macroMode = 0;
    paradigm->palettePickerMode = false;
    paradigm->centerMode = false;

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

int main(int argc, char *argv[]) {
    std::string configFilePath;
    if (argc == 1) {
        configFilePath = "./config.yml";
    } else if (argc == 2) {
        configFilePath = argv[1];
    } else {
        return 1;
    }
    return cosmographer::bootstrap(configFilePath);
}
