#pragma once

#include "cosmology/CosmologyCommunity.h"
#include "cosmology/revealeryaspect/RevealeryAspectCommunity.h"
#include "primitive/Lattice.h"
#include "cosmology/revealeryaspect/glimmering/Glimmering.h"
#include "cosmology/revealeryaspect/mesh/Mesh.h"
#include "cosmology/revealeryaspect/revealery/Revealery.h"
#include "cosmology/revealeryaspect/revealery/relics/WorkshopRevealery.h"
#include "cosmology/revealeryaspect/revealery/relics/BorderRevealery.h"
#include "cosmology/revealeryaspect/revealery/Revealeries.h"

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

class ParticleAspect : public Aspect {
public:
    ParticleAspect() {

    }

    void manifest(
            Lattice &lattice
    ) override {

    }

    void experienceEssentia() override {

    }
};

}
