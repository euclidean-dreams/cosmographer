#include "Default.h"
#include "Cosmographer.h"
#include "cloister/Constants.h"

namespace cosmographer {

// <3
// put world seed here
// <3
uint64_t worldSeed[4] = {444777444, 446777644, 456777654, 456787654};

up<Paradigm> paradigmWrapper = mkup<Paradigm>();
Paradigm *paradigm = paradigmWrapper.get();
up<Cartographer> cartographer;
up<VolitiaParadigmBond> volitiaParadigmBond;
up<VolitiaGolem> volitiaGolem;
up<Chromatica> chromatica;
up<ColorPixie> colorPixie;
up<Constants> constants;
up<Randomizer> randomizer;
up<Signalarium> signalarium;
up<Pole> pole;
up<LumionBookie> lumionBookie;
vec<float> axioms;
int microMode = 0;
int macroMode = 0;
bool palettePickerMode = false;
bool centerMode = false;

int bootstrap(std::string configFilePath) {
    Bootstrapper bootstrapper(configFilePath, 1);

    // arbiters
    auto volitiaArbiter = mksp<Arbiter<const Parcel>>();
    auto phenomenology = mksp<BufferArbiter<const Parcel>>();

    // cloister
    constants = mkup<Constants>();
    volitiaParadigmBond = mkup<VolitiaParadigmBond>(volitiaArbiter);
    volitiaGolem = mkup<VolitiaGolem>();
    randomizer = mkup<Randomizer>();
    cartographer = mkup<Cartographer>();
    chromatica = mkup<Chromatica>();
    colorPixie = mkup<ColorPixie>();
    signalarium = mkup<Signalarium>();
    pole = mkup<Pole>();
    lumionBookie = mkup<LumionBookie>();

    // extras
    axioms.push_back(0.3);
    axioms.push_back(0.1);
    axioms.push_back(1.0);
    axioms.push_back(0.4);
    axioms.push_back(0.3);
    axioms.push_back(0.7);
    axioms.push_back(0.2);
    axioms.push_back(0.2);
    axioms.push_back(0.5);
    axioms.push_back(0.5);

    initializeCoordinateHash();

    // percipient
    auto volitiaPercipientThread = VolitiaPercipient::create(
            bootstrapper.getZmqContext(),
            constants->volitiaEndpoint,
            volitiaArbiter,
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
