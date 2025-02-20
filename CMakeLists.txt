cmake_minimum_required(VERSION 3.28)
project("MWP")

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories("lib")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  enable_testing()
  add_library(Doctest INTERFACE)
  target_include_directories(Doctest INTERFACE "${CMAKE_SOURCE_DIR}/lib/doctest")
endif()

add_subdirectory("MWP")
