add_library(MWP
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Matrix.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Matrix.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Vector.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Vector.cpp"
)

target_include_directories(MWP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_subdirectory("tests")
endif()