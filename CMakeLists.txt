cmake_minimum_required(VERSION 4.0)
project(Deep_Dive_Project)
set(CMAKE_C_STANDARD 17)
set(raylib_DIR "/opt/will/lib/cmake/raylib")
find_package(raylib REQUIRED)
find_package(LibXml2 REQUIRED)
add_executable(app src/main.c src/planner.c)

target_link_libraries(app PRIVATE raylib LibXml2::LibXml2)