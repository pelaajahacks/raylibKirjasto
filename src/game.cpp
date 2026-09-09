#include "game.hpp"
#include "gameManager.hpp"



GameManager manager;


Game::Game(std::string windowName, float w, float h)
    : w(w), h(h), windowName(windowName)
{
    SetConfigFlags(FLAG_VSYNC_HINT); 
    InitWindow((int)w, (int)h, windowName.c_str());
    reset();
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

void Game::reset() {
    manager.init(w, h);
}
