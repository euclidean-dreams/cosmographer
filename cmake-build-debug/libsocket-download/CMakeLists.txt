cmake_minimum_required(VERSION 3.13)
project(libsocket-download)
include(ExternalProject)
ExternalProject_Add(
        libsocket
        GIT_REPOSITORY git@github.com:dermesser/libsocket.git
        GIT_TAG b4f5193fae541d4bf21db0cbc7af5d2ad540134f
        SOURCE_DIR "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src"
        BINARY_DIR "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
)
