#include "game.hpp"
#include "gameManager.hpp"



GameManager manager;


Game::Game(std::string windowName, float w, float h, Color bgColor)
    : w(w), h(h), windowName(windowName), bg(nullptr), bgColor(bgColor)
{
    SetConfigFlags(FLAG_VSYNC_HINT); 
    InitWindow((int)w, (int)h, windowName.c_str());
    reset();

    // background texture optional
    // bg = LoadTexture("bg.png");
    //
}

Game::~Game()
{
    // if (bg) UnloadTexture(*bg); // depends how you store it
    CloseWindow();
}

void Game::run()
{

    while (!WindowShouldClose() && manager.isRunning()) {
        
        if(IsWindowResized()) {
          w = GetScreenWidth();
          h = GetScreenHeight();
          manager.windowResized(w, h);
        }
        
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(bgColor);

        // draw background if exists
        if (bg)
        {
            DrawTexture(*bg, 0, 0, WHITE);
        }
        manager.update(dt);
        manager.draw();

        EndDrawing();


    }
}

void Game::reset() {
    manager.init(w, h);
}
