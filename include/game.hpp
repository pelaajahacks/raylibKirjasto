#pragma once

#include <string>
#include <raylib.h>
#include "entity.hpp"

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
