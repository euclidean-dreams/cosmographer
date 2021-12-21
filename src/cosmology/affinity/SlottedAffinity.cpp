#include "SlottedAffinity.h"

namespace cosmographer {

SlottedAffinity::SlottedAffinity(std::unique_ptr<std::vector<std::unique_ptr<Aspect>>> aspects)
        : aspects{move(aspects)} {

}

std::unique_ptr<Lattice> SlottedAffinity::manifest(int tick) {
    auto result = std::make_unique<Lattice>();
    auto slotSize = result->width() / aspects->size();
    for (int index = 0; index < aspects->size(); index++) {
        auto lattice = (*aspects)[index]->manifest(tick);
        for (int y = 0; y < result->height(); y++) {
            for (int x = slotSize * index; x < slotSize * (index + 1); x++) {
                auto color = lattice->getColor({x, y});
                if (color.getLightness() > 0) {
                    result->setColor({x, y}, color);
                }
            }
        }
    }
    return result;
}

void SlottedAffinity::experiencePhenomenon(const ImpresarioSerialization::Phenomenon *phenomenon) {
    for (auto &aspect: *aspects) {
        aspect->experiencePhenomenon(phenomenon);
    }
}

void SlottedAffinity::experienceEssentia(const ImpresarioSerialization::Essentia *essentia) {
    for (auto &aspect: *aspects) {
        aspect->experienceEssentia(essentia);
    }
}

}
