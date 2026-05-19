#pragma once

#include <string>
#include <raylib.h>
#include <string>
#include <vector>
#include <nametag.hpp>

class Entity {
  public:
    Entity(std::string name, Texture2D* tex, float x, float y, float w, float h, Color color);

    bool isPlayer = false;
    float speed = 400.0f;

    bool isAlive() const;

    std::string getName() const;
    Vector2 getPos() const;
    Vector2 getSize() const;

    int setPos(float x, float y);
    int destroy();


    Color getColor() const;
    int setColor(Color color);

    int draw();
    Nametag& getNametag();



  private:
    bool alive = true;
    Rectangle rect;
    std::string name = "entity";
    Texture2D* texture;
    Color color;

    Nametag nametag;
};
