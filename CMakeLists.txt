cmake_minimum_required(VERSION 3.13)
project(cosmographer VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wno-dev)

# isn't cmake such a nuisance

#       possible vantage types:
#       palantir: for a screen (  ) <- start with this one
#       keyhole: for a warble in the weave _-_-_-_
#       gubbin: for a demonstration of magic *&*

# thanks for checking out my thing
# what do you make?

# ---<3
# josiah@_-_-_-_euclideandreams_-_-_-_.art
# ----------<3

# but without the _-_-_-_

# <3

add_compile_definitions(VANTAGE=${VANTAGE})

include(lib/cmake-utils/dependency-integrator.cmake)

integrate_cmake_dependency(
        NAME impresario-utils
        GIT_URL git@github.com:impresario-systems/impresario-utils.git
        GIT_TAG origin/dev
)

# thanks to David Blackman and Sebastiano Vigna also for their xoshiro256++ implementation!

if (${VANTAGE} STREQUAL palantir)
    # no extra config necessary
elseif (${VANTAGE} STREQUAL keyhole)
    integrate_cmake_dependency(
            NAME pigpio
            GIT_URL git@github.com:joan2937/pigpio.git
            GIT_TAG c33738a320a3e28824af7807edafda440952c05d
    )
elseif (${VANTAGE} STREQUAL gubbin)
    integrate_cmake_dependency(
            NAME ws281x
            GIT_URL git@github.com:jgarff/rpi_ws281x.git
            GIT_TAG 9be313f77aa494036e2dc205b6ec2860e7ee988c
    )
else ()
    message(FATAL_ERROR "invalid vantage type specified: ${VANTAGE}")
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
        src/cloister/chromatica/palette/SingleColorPalette.h
        src/cloister/chromatica/palette/BeatPalette.cpp src/cloister/chromatica/palette/BeatPalette.h
        src/cloister/chromatica/palette/CentrifugalPalette.cpp src/cloister/chromatica/palette/CentrifugalPalette.h

        # vantage
        src/vantage/Vantage.h

        # cosmographer
        src/Cosmographer.cpp src/Cosmographer.h src/CosmographerCommunity.h
        src/cosmology/Cosmology.cpp src/cosmology/Cosmology.h src/cosmology/CosmologyCommunity.h
        src/cosmology/aspect/Aspect.cpp src/cosmology/aspect/Aspect.h src/cosmology/aspect/AspectCommunity.h

        # mesh
        src/cosmology/aspect/mesh/Mesh.cpp src/cosmology/aspect/mesh/Mesh.h src/cosmology/aspect/mesh/MeshCommunity.h
        src/cosmology/aspect/mesh/lumion/Lumion.cpp src/cosmology/aspect/mesh/lumion/Lumion.h

        # glimmering
        src/cosmology/aspect/glimmering/Glimmering.cpp src/cosmology/aspect/glimmering/Glimmering.h src/cosmology/aspect/glimmering/GlimmeringCommunity.h
        src/cosmology/aspect/revealery/Revealery.h
        src/cosmology/aspect/revealery/WorkshopRevealery.cpp src/cosmology/aspect/revealery/WorkshopRevealery.h

        # glimmer
        src/cosmology/aspect/glimmering/glimmer/Glimmer.cpp src/cosmology/aspect/glimmering/glimmer/Glimmer.h src/cosmology/aspect/glimmering/glimmer/GlimmerSoul.h

        # ephemera
        src/cosmology/aspect/glimmering/glimmer/lively/Lively.h
        src/cosmology/aspect/glimmering/glimmer/lively/Fade.h

        # illuminable
        src/cosmology/aspect/glimmering/glimmer/illuminable/Illuminable.h
        src/cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.cpp src/cosmology/aspect/glimmering/glimmer/illuminable/shape/Circle.h
)

if (${VANTAGE} STREQUAL palantir)
    set(
            SOURCE_FILES
            ${SOURCE_FILES}
            src/vantage/PalantirVantage.cpp src/vantage/PalantirVantage.h
    )
endif ()
if (${VANTAGE} STREQUAL keyhole)
    set(
            SOURCE_FILES
            ${SOURCE_FILES}
            src/vantage/keyhole/KeyholeConnection.cpp src/vantage/keyhole/KeyholeConnection.h
            src/vantage/keyhole/KeyholeVantage.cpp src/vantage/keyhole/KeyholeVantage.h
            src/vantage/keyhole/KeyholeConstants.h
    )
endif ()
if (${VANTAGE} STREQUAL gubbin)
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
        src/cosmology/aspect/glimmering/glimmer/lively/Drift.h
        src/primitive/Loci.h

        src/cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.cpp src/cosmology/aspect/glimmering/glimmer/illuminable/shape/Rectangle.h
        src/cosmology/aspect/glimmering/glimmer/lively/Grow.h
        src/cosmology/aspect/glimmering/Orchestrator.cpp src/cosmology/aspect/glimmering/Orchestrator.h
        src/cosmology/aspect/glimmering/Illuminator.cpp src/cosmology/aspect/glimmering/Illuminator.h
        src/cloister/Constants.h
        src/framework/Bindings.h
        src/cloister/Randomizer.cpp src/cloister/Randomizer.h
        src/cosmology/aspect/glimmering/glimmer/illuminable/painter/Canvas.cpp src/cosmology/aspect/glimmering/glimmer/illuminable/painter/Canvas.h
        src/cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.cpp src/cosmology/aspect/glimmering/glimmer/illuminable/painter/Painter.h
        src/cosmology/aspect/glimmering/glimmer/lindogram/DragonCurve.cpp src/cosmology/aspect/glimmering/glimmer/lindogram/DragonCurve.h
        src/cosmology/aspect/glimmering/glimmer/lindogram/DragonCurveSystem.h
        src/primitive/Signal.cpp src/primitive/Signal.h
        src/oddments/Antechamber.cpp src/oddments/Antechamber.h
        src/cosmology/aspect/glimmering/glimmer/lindogram/Wander.cpp src/cosmology/aspect/glimmering/glimmer/lindogram/Wander.h
        src/cosmology/aspect/glimmering/glimmer/illuminable/painter/PainterCommunity.h
        src/cosmology/aspect/glimmering/glimmer/GlimmerMakers.cpp src/cosmology/aspect/glimmering/glimmer/GlimmerMakers.h
        src/cosmology/aspect/glimmering/glimmer/lively/Lifespan.h
        src/framework/Element.h
        src/cosmology/aspect/glimmering/glimmer/lindogram/WorkshopCurve.cpp src/cosmology/aspect/glimmering/glimmer/lindogram/WorkshopCurve.h
        src/cosmology/aspect/revealery/SpectrumRevealery.cpp src/cosmology/aspect/revealery/SpectrumRevealery.h
        src/cosmology/aspect/glimmering/glimmer/lively/Mutator.h
        src/oddments/Tidbit.cpp src/oddments/Tidbit.h
        src/cosmology/aspect/glimmering/glimmer/lively/LumionMimic.h
        src/cosmology/aspect/revealery/BorderRevealery.cpp src/cosmology/aspect/revealery/BorderRevealery.h
        src/cloister/Pole.cpp src/cloister/Pole.h
        src/cloister/LumionBookie.cpp src/cloister/LumionBookie.h
        src/cloister/chromatica/palette/ExplorerPalette.cpp src/cloister/chromatica/palette/ExplorerPalette.h
        src/cloister/chromatica/palette/RandomPalette.cpp src/cloister/chromatica/palette/RandomPalette.h
        src/cosmology/aspect/glimmering/glimmer/lindogram/Ring.cpp src/cosmology/aspect/glimmering/glimmer/lindogram/Ring.h
        src/cosmology/aspect/glimmering/glimmer/illuminable/painter/SingleColorCanvas.cpp src/cosmology/aspect/glimmering/glimmer/illuminable/painter/SingleColorCanvas.h
        src/cloister/VolitiaGolem.cpp src/cloister/VolitiaGolem.h src/cosmology/aspect/glimmering/glimmer/lindogram/Triangle.cpp src/cosmology/aspect/glimmering/glimmer/lindogram/Triangle.h src/primitive/Loci.cpp)
list(APPEND TARGETS cosmographer)
add_executable(cosmographer src/main.cpp ${SOURCE_FILES})

# finalize
foreach (target IN LISTS TARGETS)
    target_include_directories(${target} PRIVATE src)
    if (${VANTAGE} STREQUAL keyhole)
        target_include_directories(${target} PRIVATE ${CMAKE_BINARY_DIR}/pigpio-src)
        target_link_libraries(${target} PRIVATE pigpio)
    endif ()
    if (${VANTAGE} STREQUAL gubbin)
        target_include_directories(${target} PRIVATE ${CMAKE_BINARY_DIR}/rpi_ws281x-src)
        target_link_libraries(${target} PRIVATE ws2811)
    endif ()
    target_link_libraries(${target} PRIVATE impresario-utils)
endforeach ()
