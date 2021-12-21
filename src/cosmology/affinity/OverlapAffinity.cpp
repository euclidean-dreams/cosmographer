#include "OverlapAffinity.h"

namespace cosmographer {

OverlapAffinity::OverlapAffinity(std::unique_ptr<std::vector<std::unique_ptr<Aspect>>> aspects)
        : aspects{move(aspects)} {

}

std::unique_ptr<Lattice> OverlapAffinity::manifest(int tick) {
    auto result = std::make_unique<Lattice>();
    for (auto &aspect: *aspects) {
        auto lattice = aspect->manifest(tick);
        for (int y = 0; y < lattice->height(); y++) {
            for (int x = 0; x < lattice->width(); x++) {
                auto color = lattice->getColor({x, y});
                if (color.getLightness() > 0) {
                    result->setColor({x, y}, color);
                }
            }
        }
    }
    return result;
}

void OverlapAffinity::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    for (auto &aspect: *aspects) {
        aspect->experiencePhenomenon(phenomenon);
    }
}

void OverlapAffinity::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    for (auto &aspect: *aspects) {
        aspect->experienceEssentia(essentia);
    }

}

}
