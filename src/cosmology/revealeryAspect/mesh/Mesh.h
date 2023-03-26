#ifndef COSMOGRAPHER_MESH_H
#define COSMOGRAPHER_MESH_H

#include "MeshCommunity.h"
#include "cosmology/revealeryaspect/RevealeryAspectCommunity.h"
#include "cosmology/revealeryaspect/glimmering/Glimmering.h"
#include "cosmology/revealeryaspect/revealery/Revealery.h"
#include "cosmology/revealeryaspect/mesh/lumion/Lumion.h"
#include <complex>

namespace cosmographer {

class Mesh : public Fellow<RevealeryAspectCommunity>, public Liaison<MeshCommunity> {
public:
    Mesh(
            RevealeryAspectCommunity *community
    );

    void meld();
};

}

#endif //COSMOGRAPHER_MESH_H
