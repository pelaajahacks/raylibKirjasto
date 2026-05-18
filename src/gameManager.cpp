#include "gameManager.hpp"
#include "entity.hpp"
#include <algorithm>
#include <raylib.h>

void GameManager::addEntity(const Entity& e)
{
    entities.push_back(e);
}

void GameManager::refreshEntities() {
  entities.erase(
        std::remove_if(
            entities.begin(),
            entities.end(),
            [](const Entity& e)
            {
                return !e.isAlive();
            }
        ),
        entities.end()
    );
}

void GameManager::inputLoop() {
    float dt = GetFrameTime();

    for (auto& e : entities)
    {
        if (!e.isPlayer) continue;

        Vector2 pos = e.getPos();

        if (IsKeyDown(KEY_D)) pos.x += e.speed * dt;
        if (IsKeyDown(KEY_A))  pos.x -= e.speed * dt;
        if (IsKeyDown(KEY_S))  pos.y += e.speed * dt;
        if (IsKeyDown(KEY_W))    pos.y -= e.speed * dt;

        e.setPos(pos.x, pos.y);
    }
}
void GameManager::update()
{
    inputLoop();
    refreshEntities();
}

void GameManager::draw()
{
    for (auto& e : entities)
    {
        Vector2 pos = e.getPos();
        Vector2 size = e.getSize();

        DrawRectangle(
            (int)pos.x,
            (int)pos.y,
            (int)size.x,
            (int)size.y,
            RED
        );

        e.getNametag().draw(pos.x, pos.y, size.x, size.y);
    }
}

int GameManager::init()
{
    Entity player("Pelaaja", nullptr, 100, 100, 50, 50, RED);

    player.isPlayer = true;

    entities.push_back(player);
    return 0;
}
void GameManager::drawFPS() {
    DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, PURPLE);
}
