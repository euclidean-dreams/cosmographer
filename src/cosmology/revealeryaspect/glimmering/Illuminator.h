#ifndef COSMOGRAPHER_ILLUMINATOR_H
#define COSMOGRAPHER_ILLUMINATOR_H

#include "GlimmeringCommunity.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/Glimmer.h"

namespace cosmographer {

class Illuminator : public Fellow<GlimmeringCommunity>, public Circulable {
public:
    int identifier;

    Illuminator(
            int identifier
    );

    void activate() override;
};

}

#endif //COSMOGRAPHER_ILLUMINATOR_H
