#include "game.hpp"
#include "gameManager.hpp"

GameManager manager;

Game::Game(std::string windowName, float w, float h)
    : w(w), h(h), windowName(windowName), bg(nullptr)
{
    InitWindow((int)w, (int)h, windowName.c_str());
    SetTargetFPS(60);
    manager.init();

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
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // draw background if exists
        if (bg)
        {
            DrawTexture(*bg, 0, 0, WHITE);
        }
        manager.update();
        manager.draw();

        manager.drawFPS();


        EndDrawing();
    }
}

void Game::spawnEntity(std::string name, Texture2D* tex, float x, float y, float w, float h, Color color)
{
    entities.emplace_back(name, tex, x, y, w, h, color);
}

