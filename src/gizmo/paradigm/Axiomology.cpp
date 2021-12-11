#include "Axiomology.h"

namespace cosmographer {

Axiomology::Axiomology(const impresarioUtils::Parcel &axiomologyParcel)
        : brightness{0},
          magnitude{0},
          hue{0},
          wildcards{} {
    auto axioms = impresarioUtils::Unwrap::Axiomology(axiomologyParcel)->axioms();
    brightness = axioms->Get(0);
    magnitude = axioms->Get(1);
    hue = axioms->Get(2);
    for (int index = 3; index <= 10; index++) {
        wildcards.push_back(axioms->Get(index));
    }
}

Axiomology::Axiomology(float brightness, float magnitude, float hue, std::vector<float> &wildcards)
        : brightness{brightness},
          magnitude{magnitude},
          hue{hue},
          wildcards{wildcards} {

}

float Axiomology::getBrightness() const {
    return brightness;
}

float Axiomology::getMagnitude() const {
    return magnitude;
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
