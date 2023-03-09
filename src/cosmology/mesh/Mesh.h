#ifndef COSMOGRAPHER_MESH_H
#define COSMOGRAPHER_MESH_H

#include "MeshCommunity.h"
#include "cosmology/RevealeryAspectCommunity.h"
#include "cosmology/glimmering/Glimmering.h"
#include "cosmology/revealery/Revealery.h"
#include "cosmology/mesh/lumion/Lumion.h"
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
