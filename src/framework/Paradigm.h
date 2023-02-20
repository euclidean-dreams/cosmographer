#ifndef COSMOGRAPHER_PARADIGM_H
#define COSMOGRAPHER_PARADIGM_H

#include "framework/Libs.h"
#include "framework/Macros.h"
#include "primitive/color/HSLColor.h"

namespace cosmographer {

class Paradigm : public NonCopyable {
};

extern up<Paradigm> paradigmWrapper;
extern Paradigm *paradigm;
extern up<class Cartographer> cartographer;
extern up<class VolitiaParadigmBond> volitiaParadigmBond;
extern up<class VolitiaGolem> volitiaGolem;
extern up<class Chromatica> chromatica;
extern up<class ColorPixie> colorPixie;
extern up<class Constants> constants;
extern up<class Randomizer> randomizer;
extern up<class Signalarium> signalarium;
extern up<class Pole> pole;
extern up<class LumionBookie> lumionBookie;
extern vec<float> axioms;
extern int microMode;
extern int macroMode;
extern bool centerMode;
extern int profile;

#define OPUS_PROFILE 0
#define LANTERN_PROFILE 1

}

#endif //COSMOGRAPHER_PARADIGM_H
