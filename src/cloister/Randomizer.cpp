#include "Randomizer.h"
#include "Default.h"

namespace cosmographer {

Randomizer::Randomizer(

) :
        generator{std::random_device{}()},
        distribution{0, std::numeric_limits<int>::max()} {

}

int Randomizer::generate(int exclusive_max) {
    return generateNumber(exclusive_max);
}

float Randomizer::generateProportion() {
    return cast(float, generateNumber(10000)) / 9999;
}

int Randomizer::generateNumber(int exclusive_max) {
    if (exclusive_max <= 0) {
        return 0;
    }
    auto randomNumber = distribution(generator);
    return randomNumber % exclusive_max;
}
}
