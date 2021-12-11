cmake_minimum_required(VERSION 3.13)
project(cosmographer VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(lib/cmake-utils/dependency-integrator.cmake)
integrate_cmake_dependency(
        NAME impresario-utils
        GIT_URL git@github.com:impresario-systems/impresario-utils.git
        GIT_TAG origin/dev
)

set(
        SOURCE_FILES

        src/gizmo/Coordinate.cpp src/gizmo/Coordinate.h

        src/gizmo/color/RGBColor.h
        src/gizmo/color/HSLColor.cpp src/gizmo/color/HSLColor.h

        src/Cosmographer.cpp src/Cosmographer.h
        src/cosmology/aspect/Aspect.h
        src/gizmo/Lattice.cpp src/gizmo/Lattice.h
        src/cosmology/Cosmology.cpp src/cosmology/Cosmology.h
        src/vantage/LuciferonVantage.cpp src/vantage/LuciferonVantage.h
        src/vantage/PalantirVantage.cpp src/vantage/PalantirVantage.h src/cosmology/illuminable/Illuminable.h src/cosmology/illuminable/shape/Circle.cpp src/cosmology/illuminable/shape/Circle.h src/cosmology/aspect/Plumage.cpp src/cosmology/aspect/Plumage.h src/cosmology/ephemera/Ephemera.h src/cosmology/ephemera/Bloom.cpp src/cosmology/ephemera/Bloom.h src/cosmology/ephemera/Ephemera.cpp src/cosmology/ephemera/EphemeraEcosystem.h src/percipient/AnalogoriumPercipient.cpp src/percipient/AnalogoriumPercipient.h src/vantage/Vantage.h src/gizmo/paradigm/Paradigm.cpp src/gizmo/paradigm/Paradigm.h src/percipient/VolitiaPercipient.cpp src/percipient/VolitiaPercipient.h src/Empyrium.cpp src/Empyrium.h src/Config.h src/gizmo/CoordinateTransformer.cpp src/gizmo/CoordinateTransformer.h src/cosmology/illuminable/Signal.cpp src/cosmology/illuminable/Signal.h src/gizmo/paradigm/Axiomology.cpp src/gizmo/paradigm/Axiomology.h src/gizmo/color/palette/Palette.h src/gizmo/color/palette/FrequencyPalette.cpp src/gizmo/color/palette/FrequencyPalette.h src/gizmo/color/colorium/Colorium.cpp src/gizmo/color/colorium/Colorium.h src/gizmo/color/colorium/JourneyColorium.cpp src/gizmo/color/colorium/JourneyColorium.h src/gizmo/color/palette/RandomPalette.cpp src/gizmo/color/palette/RandomPalette.h src/gizmo/color/palette/SingleColorPalette.cpp src/gizmo/color/palette/SingleColorPalette.h src/cosmology/ephemera/EphemeraEcosystem.cpp src/gizmo/color/Colorology.cpp src/gizmo/color/Colorology.h src/cosmology/illuminable/Illuminable.cpp src/cosmology/aspect/Signalarium.cpp src/cosmology/aspect/Signalarium.h src/gizmo/color/palette/FrequencyOscillationPalette.cpp src/gizmo/color/palette/FrequencyOscillationPalette.h src/gizmo/color/palette/BeatPalette.cpp src/gizmo/color/palette/BeatPalette.h)
list(APPEND TARGETS cosmographer)
add_executable(cosmographer src/main.cpp ${SOURCE_FILES})

# finalize
foreach (target IN LISTS TARGETS)
    target_include_directories(${target} PRIVATE src)
    target_link_libraries(${target} PRIVATE impresario-utils)
    target_link_libraries(${target} PRIVATE zmq)
    target_link_libraries(${target} PRIVATE pthread)
    target_link_libraries(${target} PRIVATE yaml-cpp)
endforeach ()
