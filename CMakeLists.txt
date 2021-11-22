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

SET(YAML_CPP_BUILD_TESTS OFF)
SET(YAML_CPP_INSTALL OFF)
SET(YAML_MSVC_SHARED_RT OFF)
SET(YAML_CPP_BUILD_TOOLS OFF)
SET(YAML_CPP_BUILD_CONTRIB OFF)
integrate_cmake_dependency(
        NAME yaml
        GIT_URL git@github.com:jbeder/yaml-cpp.git
        GIT_TAG 9a3624205e8774953ef18f57067b3426c1c5ada6
)

set(
        SOURCE_FILES
        src/Bootstrapper.cpp src/Bootstrapper.h
        src/Config.cpp src/Config.h

        src/gizmo/Coordinate.cpp src/gizmo/Coordinate.h

        src/gizmo/color/RGBColor.h
        src/gizmo/color/HSLColor.cpp src/gizmo/color/HSLColor.h

        src/Cosmographer.cpp src/Cosmographer.h
        src/cosmology/aspect/Aspect.h
        src/cosmology/Lattice.cpp src/cosmology/Lattice.h
        src/cosmology/aspect/SeedAspect.cpp src/cosmology/aspect/SeedAspect.h
        src/cosmology/Cosmology.cpp src/cosmology/Cosmology.h
        src/vantage/LuciferonVantage.cpp src/vantage/LuciferonVantage.h
        src/gizmo/LatticeArbiter.h src/Constants.h
        src/vantage/PalantirVantage.cpp src/vantage/PalantirVantage.h src/gizmo/LatticeArbiter.cpp)
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
