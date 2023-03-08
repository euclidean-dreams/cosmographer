#ifndef COSMOGRAPHER_MESH_H
#define COSMOGRAPHER_MESH_H

#include "MeshCommunity.h"
#include "cosmology/AspectCommunity.h"
#include "cosmology/glimmering/Glimmering.h"
#include "cosmology/revealery/Revealery.h"
#include "cosmology/mesh/lumion/Lumion.h"
#include <complex>

namespace cosmographer {

class Mesh : public Fellow<AspectCommunity>, public Liaison<MeshCommunity> {
public:
    Mesh(
            AspectCommunity *community
    );

    void meld();
};

}

#endif //COSMOGRAPHER_MESH_H
