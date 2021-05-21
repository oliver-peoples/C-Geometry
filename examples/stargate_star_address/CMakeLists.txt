cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 11)

project(Stargate)

find_package(OpenCV REQUIRED)

include_directories(~/Hamiltonian-Mathematics)
include_directories(~/C-Geometry)

# Add example to find and plot minimum permissivity for a given simulation environment

add_executable(Stargate source.cpp stargate.hpp)

target_link_libraries(Stargate ${OpenCV_LIBS})