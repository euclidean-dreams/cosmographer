#ifndef COSMOGRAPHER_ASPECT_H
#define COSMOGRAPHER_ASPECT_H

#include "cosmology/CosmologyCommunity.h"
#include "AspectCommunity.h"
#include "primitive/Lattice.h"
#include "cosmology/glimmering/Glimmering.h"
#include "cosmology/mesh/Mesh.h"
#include "cosmology/revealery/Revealery.h"
#include "cosmology/revealery/relics/WorkshopRevealery.h"
#include "cosmology/revealery/relics/BorderRevealery.h"
#include "cosmology/revealery/Revealeries.h"

namespace cosmographer {

    class Aspect : public Fellow<CosmologyCommunity>, public Liaison<AspectCommunity> {
    public:
        Aspect(
                CosmologyCommunity *community
        ) :
                Liaison<AspectCommunity>(community) {
            subCommunity.mesh = mkup<Mesh>(&subCommunity);
            subCommunity.mesh->initialize(&subCommunity);
            if (profile == LANTERN_PROFILE) {
                subCommunity.revealeries.push_back(mkup<LanternRevealery>());
            } else {
                subCommunity.revealeries.push_back(mkup<SpectrumRevealery>());
            }
            subCommunity.revealeries.push_back(mkup<OddRevealery>());
            subCommunity.revealeries.push_back(mkup<RandomRevealery>());
            subCommunity.revealeries.push_back(mkup<RandomRevealery>());
            subCommunity.revealeries.push_back(mkup<SpectrumRevealery>());
            for (auto &revealery: subCommunity.revealeries) {
                revealery->initialize(&subCommunity);
            }
            subCommunity.glimmering = mkup<Glimmering>(&subCommunity);
            subCommunity.glimmering->initialize(&subCommunity);
        }

        void manifest(
                Lattice &lattice
        ) {
            subCommunity.glimmering->illuminate(lattice);
        }

        void experienceEssentia() {
            for (auto &revealery: subCommunity.revealeries) {
                revealery->experienceSignal();
            }
            subCommunity.mesh->meld();
        }
    };

}

#endif //COSMOGRAPHER_ASPECT_H
