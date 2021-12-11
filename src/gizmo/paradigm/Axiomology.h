#ifndef COSMOGRAPHER_AXIOMOLOGY_H
#define COSMOGRAPHER_AXIOMOLOGY_H

#include <ImpresarioUtils.h>
#include "gizmo/color/HSLColor.h"

namespace cosmographer {

class Axiomology {
private:
    float brightness;
    float magnitude;
    float hue;
    std::vector<float> wildcards;

public:
    explicit Axiomology(const impresarioUtils::Parcel &axiomologyParcel);

    Axiomology(float brightness, float magnitude, float hue, std::vector<float> &wildcards);

    float getBrightness() const;

    float getMagnitude() const;

    float getHue() const;

    int getScaledHue() const;

    float getWildcard(int index) const;
};

}

#endif //COSMOGRAPHER_AXIOMOLOGY_H
