#pragma once

#include <string>
#include <raylib.h>
#include "entities/entity.hpp"
#include "core/gameManager.hpp"

class Game {
public:
    Game(std::string windowName, float w, float h);
    ~Game();

    void run();
    void reset();

private:
    float w, h;
    std::string windowName;
};
