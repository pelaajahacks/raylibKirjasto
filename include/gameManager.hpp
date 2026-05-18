#pragma once

#include <vector>
#include "entity.hpp"

class GameManager {
public:
    void addEntity(const Entity& e);

    void update();
    void draw();
    void drawFPS();

    int init();

    void inputLoop();
    void refreshEntities();

private:
    std::vector<Entity> entities;
};
