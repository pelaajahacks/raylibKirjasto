cmake_minimum_required(VERSION 3.15)
project(kirjasto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(raylib CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES
    "src/*.cpp"
)

add_executable(kirjasto ${SOURCES})

target_include_directories(kirjasto PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/raygui/src
    ${CMAKE_SOURCE_DIR}/external/layout
)

target_link_libraries(kirjasto PRIVATE
    raylib
)
