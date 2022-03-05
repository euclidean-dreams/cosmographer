#include "default.h"
#include "Cosmographer.h"

namespace cosmographer {

int bootstrap() {
    std::string configFilePath = "./config.yml";
    Bootstrapper bootstrapper(configFilePath, 1);

    // percipient
    auto axiomArbiter = mksp<Arbiter<const Parcel>>();
    auto phenomenology = mksp<BufferArbiter<const Parcel>>();
    auto volitiaPercipientThread = VolitiaPercipient::create(
            bootstrapper.getZmqContext(),
            VOLITIA_ENDPOINT,
            axiomArbiter,
            phenomenology
    );

    // build paradigm
    auto paradigm = mkup<Paradigm>();
    paradigm->axioms.resize(AXIOMOLOGY_SIZE, 0.5);
    paradigm->latticeWidth = LATTICE_WIDTH;
    paradigm->latticeHeight = LATTICE_HEIGHT;

    paradigm->cloister = mkup<CloisterCommunity>(paradigm.get());
    paradigm->cloister->axiomRefresher = mkup<AxiomRefresher>(axiomArbiter);
    paradigm->cloister->axiomRefresher->initialize(paradigm->cloister.get());
    paradigm->cloister->cartographer = mkup<Cartographer>();
    paradigm->cloister->cartographer->initialize(paradigm->cloister.get());
    paradigm->cloister->chromatica = mkup<Chromatica>(paradigm->cloister.get());
    paradigm->cloister->chromatica->initialize(paradigm->cloister.get());

    auto cosmographer = mkup<Cosmographer>(
            bootstrapper.getZmqContext(),
            paradigm.get(),
            mv(phenomenology)
    );
    auto cosmographerThread = Circlet::begin(mv(cosmographer));

    // TODO get rid of this thing
    int result = system("cd /home/josiah/projects/code/impresario-systems/conductor && ./conductor.sh &");
    result = system("cd /home/josiah/projects/code/impresario-systems/palantir && ./palantir.sh &");

    // go time!
    cosmographerThread->join();
    volitiaPercipientThread->join();

    return 0;
}

}

int main() {
    return cosmographer::bootstrap();
}
