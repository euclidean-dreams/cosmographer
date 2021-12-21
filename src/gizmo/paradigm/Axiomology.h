#ifndef COSMOGRAPHER_AXIOMOLOGY_H
#define COSMOGRAPHER_AXIOMOLOGY_H

#include <ImpresarioUtils.h>
#include "gizmo/color/HSLColor.h"

namespace cosmographer {

class Axiomology {
private:
    const int wildcardCount = 5;

    float brightness;
    float gain;
    float ephemeraNormalizationScale;
    float ephemeraSpawnThreshold;
    float hue;
    std::vector<float> wildcards;

public:
    Axiomology();

    explicit Axiomology(const impresarioUtils::Parcel &axiomologyParcel);

    float getBrightness() const;

    float getGain() const;

    float getEphemeraNormalizationScale() const;

    float getEphemeraSpawnThreshold() const;

    float getHue() const;

    int getScaledHue() const;

    float getWildcard(int index) const;
};

}

#endif //COSMOGRAPHER_AXIOMOLOGY_H
