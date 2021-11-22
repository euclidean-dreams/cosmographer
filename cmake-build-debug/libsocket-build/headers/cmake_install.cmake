# Install script for directory: /home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libsocket" TYPE FILE FILES
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./unixdgram.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./exception.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./inetclientdgram.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./libinetsocket.h"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./unixserverstream.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./dgramclient.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./streamclient.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./inetserverstream.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./unixclientdgram.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./socket.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./inetbase.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./inetserverdgram.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./unixclientstream.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./libunixsocket.h"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./select.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./inetclientstream.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./unixbase.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./unixserverdgram.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./inetdgram.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./dgramoverstream.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./framing.hpp"
    "/home/josiah/projects/code/impresario-systems/cosmographer/cmake-build-debug/libsocket-src/headers/./epoll.hpp"
    )
endif()

