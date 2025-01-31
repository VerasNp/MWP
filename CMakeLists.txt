cmake_minimum_required(VERSION 3.28)
project("mwp")

include_directories("lib")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  enable_testing()
  add_library(Doctest INTERFACE)
  target_include_directories(Doctest INTERFACE "${CMAKE_SOURCE_DIR}/lib/doctest")
endif()

add_subdirectory("MWP")
