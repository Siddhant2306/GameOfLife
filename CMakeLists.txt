cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 🟢 Tell CMake where to find SFML (update this path)
set(SFML_DIR "C:/Users/Siddhant/OneDrive/Documents/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib")

# 🧠 This command automatically finds all include paths and libraries
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Create your executable
file(GLOB SOURCES src/*.cpp)
add_executable(GameOfLife ${SOURCES})

# Link SFML automatically
target_link_libraries(GameOfLife PRIVATE sfml-graphics sfml-window sfml-system)
