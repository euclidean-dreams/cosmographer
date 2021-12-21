#include "PassthroughAffinity.h"

namespace cosmographer {

PassthroughAffinity::PassthroughAffinity(std::unique_ptr<Aspect> aspect)
        : aspect{move(aspect)} {

}

std::unique_ptr<Lattice> PassthroughAffinity::manifest(int tick) {
    return aspect->manifest(tick);
}

void PassthroughAffinity::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    aspect->experiencePhenomenon(phenomenon);
}

void PassthroughAffinity::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    aspect->experienceEssentia(essentia);
}

}
