#pragma once

#include <string>
#include <raylib.h>

class GameManager;

class Game {
public:
    Game(std::string windowName, int w, int h, GameManager& manager);
    ~Game();

    void run();
    void reset();

private:
    int w, h;
    std::string windowName;

    GameManager& manager;
};
