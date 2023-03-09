cmake_minimum_required(VERSION 3.13)
project(cosmographer VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# isn't cmake such a nuisance

#       possible vantage types:
#       percipia: for a screen (  ) <- start with this one
#       keyhole: for a warble in the weave _-_-_-_
#       gubbin: for a demonstration of magic *&*

# thanks for checking out my thing
# what do you make?

# ---<3
# josiah@_-_-_-_euclideandreams_-_-_-_.art
# ----------<3

# but without the _-_-_-_

# <3

add_compile_definitions(VANTAGE=${_vantage})

include(lib/cmake-utils/dependency-integrator.cmake)

integrate_cmake_dependency(
        NAME impresario-utils
        GIT_URL git@github.com:impresario-systems/impresario-utils.git
        GIT_TAG origin/flow
)

# thanks to David Blackman and Sebastiano Vigna also for their xoshiro256++ implementation!

if (_vantage STREQUAL percipia)
    # no extra config necessary
elseif (_vantage STREQUAL keyhole)
    integrate_cmake_dependency(
            NAME pigpio
            GIT_URL git@github.com:joan2937/pigpio.git
            GIT_TAG c33738a320a3e28824af7807edafda440952c05d
    )
elseif (_vantage STREQUAL gubbin)
    integrate_cmake_dependency(
            NAME ws281x
            GIT_URL git@github.com:jgarff/rpi_ws281x.git
            GIT_TAG 9be313f77aa494036e2dc205b6ec2860e7ee988c
    )
else ()
    message(FATAL_ERROR "invalid vantage type specified: _vantage")
endif ()

set(
        SOURCE_FILES

        # primitive
        src/primitive/Lattice.cpp src/primitive/Lattice.h
        src/primitive/color/HSLColor.cpp src/primitive/color/HSLColor.h
        src/primitive/color/RGBColor.h

        # oddments
        src/oddments/SignalAverage.cpp src/oddments/SignalAverage.h


        # framework
        src/framework/Paradigm.h
        src/framework/Macros.h
        src/framework/Framework.h
        src/framework/Libs.h
        src/framework/Community.h

        # cloister
        src/cloister/Cloister.h
        src/cloister/Cartographer.cpp src/cloister/Cartographer.h
        src/cloister/VolitiaParadigmBond.cpp src/cloister/VolitiaParadigmBond.h

        # chromatica
        src/cloister/chromatica/Chromatica.cpp src/cloister/chromatica/Chromatica.h src/cloister/chromatica/ChromaticaCommunity.h
        src/cloister/ColorPixie.cpp src/cloister/ColorPixie.h
        src/cloister/chromatica/palette/Palette.h
        src/cloister/chromatica/palette/BeatPalette.cpp src/cloister/chromatica/palette/BeatPalette.h
        src/cloister/chromatica/palette/CentrifugalPalette.cpp src/cloister/chromatica/palette/CentrifugalPalette.h

        # vantage
        src/vantage/Vantage.h

        # cosmographer
        src/Cosmographer.cpp src/Cosmographer.h src/CosmographerCommunity.h
        src/cosmology/Cosmology.cpp src/cosmology/Cosmology.h src/cosmology/CosmologyCommunity.h
        src/cosmology/Aspect.h src/cosmology/revealeryaspect/RevealeryAspectCommunity.h

        # mesh
        src/cosmology/revealeryaspect/mesh/Mesh.cpp src/cosmology/revealeryaspect/mesh/Mesh.h src/cosmology/revealeryaspect/mesh/MeshCommunity.h
        src/cosmology/revealeryaspect/mesh/lumion/Lumion.cpp src/cosmology/revealeryaspect/mesh/lumion/Lumion.h

        # glimmering
        src/cosmology/revealeryaspect/glimmering/Glimmering.cpp src/cosmology/revealeryaspect/glimmering/Glimmering.h src/cosmology/revealeryaspect/glimmering/GlimmeringCommunity.h
        src/cosmology/revealeryaspect/revealery/Revealery.h
        src/cosmology/revealeryaspect/revealery/relics/WorkshopRevealery.cpp src/cosmology/revealeryaspect/revealery/relics/WorkshopRevealery.h

        # glimmer
        src/cosmology/revealeryaspect/glimmering/glimmer/Glimmer.cpp src/cosmology/revealeryaspect/glimmering/glimmer/Glimmer.h src/cosmology/revealeryaspect/glimmering/glimmer/GlimmerSoul.h

        # ephemera
        src/cosmology/revealeryaspect/glimmering/glimmer/lively/Lively.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lively/Fade.h

        # illuminable
        src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/Illuminable.h
        src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/shape/Circle.cpp src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/shape/Circle.h
)

if (_vantage STREQUAL percipia)
    set(
            SOURCE_FILES
            ${SOURCE_FILES}
            src/vantage/PercipiaVantage.cpp src/vantage/PercipiaVantage.h
    )
endif ()
if (_vantage STREQUAL keyhole)
    set(
            SOURCE_FILES
            ${SOURCE_FILES}
            src/vantage/keyhole/KeyholeConnection.cpp src/vantage/keyhole/KeyholeConnection.h
            src/vantage/keyhole/KeyholeVantage.cpp src/vantage/keyhole/KeyholeVantage.h
            src/vantage/keyhole/KeyholeConstants.h
    )
endif ()
if (_vantage STREQUAL gubbin)
    set(
            SOURCE_FILES
            ${SOURCE_FILES}
    )
endif ()

# unsorted stack
set(
        SOURCE_FILES
        ${SOURCE_FILES}
        src/cloister/Signalarium.cpp src/cloister/Signalarium.h
        src/Default.h
        src/framework/Minimal.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lively/Drift.h
        src/primitive/Loci.h

        src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/shape/Rectangle.cpp src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/shape/Rectangle.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lively/Grow.h
        src/cosmology/revealeryaspect/glimmering/Orchestrator.cpp src/cosmology/revealeryaspect/glimmering/Orchestrator.h
        src/cosmology/revealeryaspect/glimmering/Illuminator.cpp src/cosmology/revealeryaspect/glimmering/Illuminator.h
        src/cloister/Constants.h
        src/framework/Bindings.h
        src/cloister/Randomizer.cpp src/cloister/Randomizer.h
        src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/Canvas.cpp src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/Canvas.h
        src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/Painter.cpp src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/Painter.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/DragonCurve.cpp src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/DragonCurve.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/DragonCurveSystem.h
        src/primitive/Signal.cpp src/primitive/Signal.h
        src/oddments/Antechamber.cpp src/oddments/Antechamber.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/Wander.cpp src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/Wander.h
        src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h
        src/cosmology/revealeryaspect/glimmering/glimmer/GlimmerMakers.cpp src/cosmology/revealeryaspect/glimmering/glimmer/GlimmerMakers.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lively/Lifespan.h
        src/framework/Element.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/WorkshopCurve.cpp src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/WorkshopCurve.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lively/Mutator.h
        src/oddments/Tidbit.cpp src/oddments/Tidbit.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lively/LumionMimic.h
        src/cosmology/revealeryaspect/revealery/relics/BorderRevealery.cpp src/cosmology/revealeryaspect/revealery/relics/BorderRevealery.h
        src/cloister/Pole.cpp src/cloister/Pole.h
        src/cloister/LumionBookie.cpp src/cloister/LumionBookie.h
        src/cloister/chromatica/palette/RandomPalette.cpp src/cloister/chromatica/palette/RandomPalette.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/Fuzz.cpp src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/Fuzz.h
        src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/SingleColorCanvas.cpp src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/SingleColorCanvas.h
        src/cloister/VolitiaGolem.cpp src/cloister/VolitiaGolem.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/Triangle.cpp src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/Triangle.h
        src/primitive/Loci.cpp
        src/cosmology/revealeryaspect/revealery/Revealeries.h
        src/cosmology/revealeryaspect/glimmering/glimmer/lindogram/Odds.h src/cosmology/revealeryaspect/glimmering/glimmer/illuminable/Illuminables.h src/cloister/chromatica/Palettes.h src/oddments/Oddments.h)
list(APPEND TARGETS cosmographer)
add_executable(cosmographer src/main.cpp ${SOURCE_FILES})

# finalize
foreach (target IN LISTS TARGETS)
    target_include_directories(${target} PRIVATE src)
    if (_vantage STREQUAL keyhole)
        target_include_directories(${target} PRIVATE ${CMAKE_BINARY_DIR}/pigpio-src)
        target_link_libraries(${target} PRIVATE pigpio)
    endif ()
    if (_vantage STREQUAL gubbin)
        target_include_directories(${target} PRIVATE ${CMAKE_BINARY_DIR}/rpi_ws281x-src)
        target_link_libraries(${target} PRIVATE ws2811)
    endif ()
    target_link_libraries(${target} PRIVATE impresario-utils)
endforeach ()
