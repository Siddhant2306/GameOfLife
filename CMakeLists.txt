cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/lib/cmake/SFML")

# Try to find SFML (will look in SFML_DIR)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# (Optional) if you placed headers somewhere else, you can add include directories:
include_directories(${CMAKE_SOURCE_DIR}/includes/SFML)

# Create your executable
file(GLOB SOURCES src/*.cpp)
add_executable(GameOfLife ${SOURCES})

# Link SFML automatically
target_link_libraries(GameOfLife PRIVATE sfml-graphics sfml-window sfml-system)

