cmake_minimum_required(VERSION 4.0)
project(MyCal VERSION 1.0.0
              DESCRIPTION "A Calendar + Planner App"
              LANGUAGES C)
              
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(PROJECT_LICENSE "GNU General Public License version 3")
set(PROJECT_AUTHOR "Wdboyes13")
set(PROJECT_SITE "https://github.com/Wdboyes13/MyCal")

set(raylib_DIR "/opt/will/lib/cmake/raylib")
find_package(raylib REQUIRED)
find_package(LibXml2 REQUIRED)
add_executable(app src/main.c src/planner.c)

target_link_libraries(app PRIVATE raylib LibXml2::LibXml2)