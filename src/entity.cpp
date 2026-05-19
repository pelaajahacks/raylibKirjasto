#include "entity.hpp"
#include "nametag.hpp"
#include <algorithm>

Entity::Entity(std::string name, float x, float y, float w, float h, Texture2D* tex, Color color)
    : name(name),
      texture(tex),
      rect{x, y, w, h},
      color(color),
      nametag(name)
{
}

std::string Entity::getName() const {
  return name;
}

Vector2 Entity::getPos() const
{
    return Vector2{ rect.x, rect.y };
}
Vector2 Entity::getSize() const
{
    return { rect.width, rect.height };
}

int Entity::setPos(float nx, float ny)
{
    float screenW = GetScreenWidth();
    float screenH = GetScreenHeight();

    // clamp TOP-LEFT position
    nx = std::clamp(nx, 0.0f, screenW - rect.width);
    ny = std::clamp(ny, 0.0f, screenH - rect.height);

    rect.x = nx;
    rect.y = ny;

    return 1;
}

int Entity::destroy()
{
    alive = false;
    return 1;
}

bool Entity::isAlive() const
{
    return alive;
}

Color Entity::getColor() const
{
    return color;
}

int Entity::setColor(Color c)
{
    color = c;
    return 1;
}

int Entity::draw()
{
  if (texture != nullptr) {
    DrawTextureRec(*texture, rect, Vector2{rect.x, rect.y}, WHITE);
  }
  else {
    DrawRectangleRec(rect, color);
  }
  nametag.draw(rect.x, rect.y, rect.width, rect.height);

  
  return 1;
}

Nametag& Entity::getNametag()
{
    return nametag;
}
