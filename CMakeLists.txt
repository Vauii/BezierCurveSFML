cmake_minimum_required(VERSION 3.10)
project(BezierVisualizerSFML)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_GENERATOR_TOOLSET "host=x64")
set(CMAKE_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.40.33807/bin/Hostx64/x64/cl.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.40.33807/bin/Hostx64/x64/cl.exe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /utf-8")

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

message(STATUS "SFML source directory: ${SFML_SOURCE_DIR}")
message(STATUS "SFML binary directory: ${SFML_BINARY_DIR}")

include_directories(${CMAKE_SOURCE_DIR}/include/core)
include_directories(${CMAKE_SOURCE_DIR}/include/visualization)
include_directories(${CMAKE_SOURCE_DIR}/include/geometry)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)


add_executable(main main.cpp ${SOURCES})
target_include_directories(main PRIVATE ${SFML_INCLUDE_DIR})
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(main PRIVATE cxx_std_17)
