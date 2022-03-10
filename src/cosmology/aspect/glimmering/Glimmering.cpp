#include "Glimmering.h"

namespace cosmographer {

Glimmering::Glimmering(
        AspectCommunity *community
) :
        Liaison<GlimmeringCommunity>(community) {
    subCommunity.orchestrator = mkup<Orchestrator>();
    subCommunity.orchestrator->initialize(&subCommunity);
    for (int identifier = 0; identifier < CONSTANTS->illuminatorThreadCount; identifier++) {
        auto illuminator = mkup<Illuminator>(identifier);
        illuminator->initialize(&subCommunity);
        auto illuminatorThread = Circlet::begin(mv(illuminator));
        subCommunity.illuminatorThreads.push_back(mv(illuminatorThread));
    }
    subCommunity.illuminatorLattices.resize(CONSTANTS->illuminatorThreadCount);
    subCommunity.illuminatorTasking.resize(CONSTANTS->illuminatorThreadCount);
    subCommunity.finishedIlluminators = 0;
}

void Glimmering::illuminate(
        Lattice &lattice
) {
    if (PARADIGM->mode == CLEAR_MODE) {
        subCommunity.glimmers.clear();
    }
    subCommunity.orchestrator->orchestrate(lattice);
}

void Glimmering::addGlimmer(
        up<Glimmer> glimmer
) {
    glimmer->initialize(&subCommunity);
    subCommunity.glimmers.push_back(mv(glimmer));
}

}
