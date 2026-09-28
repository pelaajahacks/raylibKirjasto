#include "core/game.hpp"
#include "core/manager/gameManager.hpp"

GameManager manager;

Game::Game(std::string windowName, int w, int h, GameManager& manager)
    : w(w), h(h), windowName(windowName), manager(manager)
{
    SetConfigFlags(FLAG_VSYNC_HINT); 
    InitWindow((int)w, (int)h, windowName.c_str());
}

Game::~Game() {
    CloseWindow();
}

void Game::run() {

    while (!WindowShouldClose() && manager.isRunning()) { 
        if(IsWindowResized()) {
          w = GetScreenWidth();
          h = GetScreenHeight();
          manager.windowResized(w, h);
        }
        
        float dt = GetFrameTime();
        BeginDrawing();

        manager.update(dt);
        manager.draw();

        EndDrawing();
    }
}

