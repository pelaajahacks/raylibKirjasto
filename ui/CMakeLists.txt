cmake_minimum_required(VERSION 3.15)
project(ui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)

if(NOT DEFINED UI_EXTERNAL_DIR)
    get_filename_component(UI_EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../external" ABSOLUTE)
endif()

file(GLOB_RECURSE UI_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(ui STATIC ${UI_SOURCES})

target_include_directories(ui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${UI_EXTERNAL_DIR}/raygui/src
    ${UI_EXTERNAL_DIR}/layout
)

target_link_libraries(ui PUBLIC
    raylib
)