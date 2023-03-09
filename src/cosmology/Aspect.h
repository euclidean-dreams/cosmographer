#ifndef COSMOGRAPHER_ASPECT_H
#define COSMOGRAPHER_ASPECT_H

#include "cosmology/CosmologyCommunity.h"
#include "RevealeryAspectCommunity.h"
#include "primitive/Lattice.h"
#include "cosmology/glimmering/Glimmering.h"
#include "cosmology/mesh/Mesh.h"
#include "cosmology/revealery/Revealery.h"
#include "cosmology/revealery/relics/WorkshopRevealery.h"
#include "cosmology/revealery/relics/BorderRevealery.h"
#include "cosmology/revealery/Revealeries.h"

namespace cosmographer {
    class Aspect : public Fellow<CosmologyCommunity> {
    public:
        virtual void manifest(Lattice &lattice) = 0;

        virtual void experienceEssentia() = 0;
    };

    class RevealeryAspect : public Aspect, public Liaison<RevealeryAspectCommunity> {
    public:
        RevealeryAspect(
                CosmologyCommunity *community
        ) :
                Liaison<RevealeryAspectCommunity>(community) {
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
        ) override {
            subCommunity.glimmering->illuminate(lattice);
        }

        void experienceEssentia() override {
            for (auto &revealery: subCommunity.revealeries) {
                revealery->experienceSignal();
            }
            subCommunity.mesh->meld();
        }
    };

}

#endif //COSMOGRAPHER_ASPECT_H
