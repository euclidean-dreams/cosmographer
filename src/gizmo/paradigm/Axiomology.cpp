#include "Axiomology.h"

namespace cosmographer {

Axiomology::Axiomology()
        : brightness{0.5},
          gain{0.5},
          ephemeraNormalizationScale{0.5},
          ephemeraSpawnThreshold{0.5},
          hue{0.5},
          wildcards{} {
    for (int index = 0; index < wildcardCount; index++) {
        wildcards.push_back(0.5);
    }
}

Axiomology::Axiomology(const impresarioUtils::Parcel &axiomologyParcel)
        : Axiomology{} {
    auto axioms = impresarioUtils::Unwrap::Axiomology(axiomologyParcel)->axioms();
    if (axioms->size() > 0) {
        brightness = axioms->Get(0);
        gain = axioms->Get(1);
        ephemeraNormalizationScale = axioms->Get(2);
        ephemeraSpawnThreshold = axioms->Get(3);
        hue = axioms->Get(4);
        for (int index = 0; index < wildcardCount; index++) {
            wildcards[index] = axioms->Get(index + 5);
        }
    }
}

float Axiomology::getBrightness() const {
    return brightness;
}

float Axiomology::getGain() const {
    return gain;
}

float Axiomology::getEphemeraNormalizationScale() const {
    return ephemeraNormalizationScale;
}

float Axiomology::getEphemeraSpawnThreshold() const {
    return ephemeraSpawnThreshold;
}

float Axiomology::getHue() const {
    return hue;
}

int Axiomology::getScaledHue() const {
    return HSL_HUE_MAX * hue;
}

float Axiomology::getWildcard(int index) const {
    return wildcards[index];
}

}
