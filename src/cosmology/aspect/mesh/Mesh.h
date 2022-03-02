#ifndef COSMOGRAPHER_MESH_H
#define COSMOGRAPHER_MESH_H

#include "MeshCommunity.h"
#include "cosmology/aspect/AspectCommunity.h"
#include "cosmology/aspect/glimmering/Glimmering.h"
#include "cosmology/aspect/mesh/lumion/Lumion.h"

namespace cosmographer {

class Mesh : public Fellow<AspectCommunity>, public Liaison<MeshCommunity> {
public:
    Mesh(
            AspectCommunity *community,
            int glimmerCount
    );

    void meld(
            vec<float> &signal
    );
};

}

#endif //COSMOGRAPHER_MESH_H
