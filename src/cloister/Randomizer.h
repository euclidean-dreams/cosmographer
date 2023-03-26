#ifndef COSMOGRAPHER_RANDOMIZER_H
#define COSMOGRAPHER_RANDOMIZER_H

#include <stdint.h>
#include "Default.h"

namespace cosmographer {

extern uint64_t worldSeed[4];

class xorshiro {
/*  Written in 2019 by David Blackman and Sebastiano Vigna (vigna@acm.org)

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.

See <http://creativecommons.org/publicdomain/zero/1.0/>. */

// thanks friends! <3
public:
    static inline uint64_t rotl(const uint64_t x, int k) {
        return (x << k) | (x >> (64 - k));
    }

    static uint64_t next(void) {
        const uint64_t result = rotl(worldSeed[0] + worldSeed[3], 23) + worldSeed[0];

        const uint64_t t = worldSeed[1] << 17;

        worldSeed[2] ^= worldSeed[0];
        worldSeed[3] ^= worldSeed[1];
        worldSeed[1] ^= worldSeed[2];
        worldSeed[0] ^= worldSeed[3];

        worldSeed[2] ^= t;

        worldSeed[3] = rotl(worldSeed[3], 45);

        return result;
    }

/* This is the jump function for the generator. It is equivalent
   to 2^128 calls to next(); it can be used to generate 2^128
   non-overlapping subsequences for parallel computations. */

    static void jump(void) {
        static const uint64_t JUMP[] = {0x180ec6d33cfd0aba, 0xd5a61266f0c9392c, 0xa9582618e03fc9aa, 0x39abdc4529b1661c};

        uint64_t s0 = 0;
        uint64_t s1 = 0;
        uint64_t s2 = 0;
        uint64_t s3 = 0;
        for (int i = 0; i < sizeof JUMP / sizeof *JUMP; i++)
            for (int b = 0; b < 64; b++) {
                if (JUMP[i] & UINT64_C(1) << b) {
                    s0 ^= worldSeed[0];
                    s1 ^= worldSeed[1];
                    s2 ^= worldSeed[2];
                    s3 ^= worldSeed[3];
                }
                next();
            }

        worldSeed[0] = s0;
        worldSeed[1] = s1;
        worldSeed[2] = s2;
        worldSeed[3] = s3;
    }

/* This is the long-jump function for the generator. It is equivalent to
   2^192 calls to next(); it can be used to generate 2^64 starting points,
   from each of which jump() will generate 2^64 non-overlapping
   subsequences for parallel distributed computations. */

    static void long_jump(void) {
        static const uint64_t LONG_JUMP[] = {0x76e15d3efefdcbbf, 0xc5004e441c522fb3, 0x77710069854ee241,
                                             0x39109bb02acbe635};

        uint64_t s0 = 0;
        uint64_t s1 = 0;
        uint64_t s2 = 0;
        uint64_t s3 = 0;
        for (int i = 0; i < sizeof LONG_JUMP / sizeof *LONG_JUMP; i++)
            for (int b = 0; b < 64; b++) {
                if (LONG_JUMP[i] & UINT64_C(1) << b) {
                    s0 ^= worldSeed[0];
                    s1 ^= worldSeed[1];
                    s2 ^= worldSeed[2];
                    s3 ^= worldSeed[3];
                }
                next();
            }

        worldSeed[0] = s0;
        worldSeed[1] = s1;
        worldSeed[2] = s2;
        worldSeed[3] = s3;
    }
};

class Randomizer {
private:
    static int generateNumber(int exclusive_max) {
        if (exclusive_max <= 0) {
            return 0;
        }
        return xorshiro::next() % exclusive_max;
    }

public:
    static int generate(int exclusive_max) {
        return generateNumber(exclusive_max);
    }

    static float generateProportion() {
        return cast(float, generateNumber(10000)) / 9999;
    }

    static float generateSign() {
        auto comparable = generateProportion() * 20 - 10;
        if (comparable > 0) {
            return 1;
        } else {
            return -1;
        }
    }
};

}

#endif //COSMOGRAPHER_RANDOMIZER_H
