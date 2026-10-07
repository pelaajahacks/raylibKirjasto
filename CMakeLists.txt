cmake_minimum_required(VERSION 3.15)
project(kirjasto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Imported targets are directory scoped, so each directory that links raylib
# needs its own find_package; libs/ui and libs/engine keep theirs so they stay
# buildable on their own.
find_package(raylib CONFIG REQUIRED)

add_subdirectory(libs/ui)
add_subdirectory(libs/engine)

add_executable(kirjasto
    src/main.cpp
    src/game/entities/rocket/extra/bar.cpp
    src/game/entities/rocket/rocket.cpp
    src/game/entities/rocket/rocketPlatform.cpp
    src/game/entities/rocket/utils/winloseAnnouncement.cpp
    src/game/screens/gameScreen.cpp
    src/game/screens/mainMenu/mainMenuScreen.cpp
)

target_include_directories(kirjasto PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(kirjasto PRIVATE
    raylib
    ui
    engine
)
