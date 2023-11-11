#ifndef COSMOGRAPHER_MESH_H
#define COSMOGRAPHER_MESH_H

#include "MeshCommunity.h"
#include "cosmology/revealeryAspect/RevealeryAspectCommunity.h"
#include "cosmology/revealeryAspect/glimmering/Glimmering.h"
#include "cosmology/revealeryAspect/revealery/Revealery.h"
#include "cosmology/revealeryAspect/mesh/lumion/Lumion.h"
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
