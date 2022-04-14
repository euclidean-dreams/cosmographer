#include "Glimmering.h"

namespace cosmographer {

Glimmering::Glimmering(
        AspectCommunity *community
) :
        Liaison<GlimmeringCommunity>(community) {
    subCommunity.orchestrator = mkup<Orchestrator>();
    subCommunity.orchestrator->initialize(&subCommunity);
    int illuminatorCountWithOrchestrator = CONSTANTS->illuminatorThreadCount + 1;
    subCommunity.kickoffAntechamber = mkup<Antechamber>(illuminatorCountWithOrchestrator);
    subCommunity.completionAntechamber = mkup<Antechamber>(illuminatorCountWithOrchestrator);
    subCommunity.illuminatorLattices.resize(CONSTANTS->illuminatorThreadCount);
    subCommunity.illuminatorTasking.resize(CONSTANTS->illuminatorThreadCount);
    for (int identifier = 0; identifier < CONSTANTS->illuminatorThreadCount; identifier++) {
        auto illuminator = mkup<Illuminator>(identifier);
        illuminator->initialize(&subCommunity);
        auto illuminatorThread = Circlet::begin(mv(illuminator));
        subCommunity.illuminatorThreads.push_back(mv(illuminatorThread));
    }
}

void Glimmering::illuminate(
        Lattice &lattice
) {
    subCommunity.orchestrator->orchestrate(lattice);
}

void Glimmering::addGlimmer(
        up<Glimmer> glimmer
) {
    subCommunity.glimmers.push_back(mv(glimmer));
}

GlimmeringCommunity *Glimmering::fetchSubcommunity() {
    return &subCommunity;
}

}
