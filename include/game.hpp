#pragma once

#include <string>
#include <raylib.h>
#include "entity.hpp"

class Game {
public:
    Game(std::string windowName, float w, float h);
    ~Game();

    void run();
    void spawnEntity(std::string name, Texture2D* tex, float x, float y, float w, float h, Color color);



private:
    float w, h;
    std::string windowName;
    Texture2D* bg;

    std::vector<Entity> entities;
};
