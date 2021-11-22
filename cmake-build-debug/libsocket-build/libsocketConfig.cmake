set(libsocket_INCLUDE_DIRS "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers")

set(libsocket_BINARY_DIR "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-build")

include(${libsocket_BINARY_DIR}/libsocketTargets.cmake)

set(libsocket_LIBRARIES socket++)
