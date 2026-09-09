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

Vector2 Entity::getPos() const {
    return Vector2{ rect.x, rect.y };
}
Vector2 Entity::getSize() const {
    return { rect.width, rect.height };
}

int Entity::setPos(float nx, float ny) {
    float screenW = GetScreenWidth();
    float screenH = GetScreenHeight();

    // clamp TOP-LEFT position
    //nx = std::clamp(nx, 0.0f, screenW - rect.width);
    //ny = std::clamp(ny, 0.0f, screenH - rect.height);

    rect.x = nx;
    rect.y = ny;

    return 1;
}

float Entity::getRotation() const {
  return rotation;
}

void Entity::setRotation(float rot) {
  rotation = rot;
}

int Entity::destroy() {
    alive = false;
    return 1;
}

bool Entity::isAlive() const {
    return alive;
}

Color Entity::getColor() const {
    return color;
}

int Entity::setColor(Color c) {
    color = c;
    return 1;
}

int Entity::draw() {
  if (texture != nullptr) {
    DrawTextureRec(*texture, rect, Vector2{rect.x, rect.y}, WHITE);
  }
  else {
    DrawRectanglePro(rect, Vector2{rect.width*0.5f, rect.height*0.5f}, rotation, color);
  }
  if(name != "") {
    nametag.draw(rect.x, rect.y, rect.width, rect.height);
  }

  
  return 1;
}

Nametag& Entity::getNametag() {
    return nametag;
}

void Entity::input(float dt) {
    Vector2 pos = getPos();

    if (IsKeyDown(KEY_D)) pos.x += speed * dt;
    if (IsKeyDown(KEY_A)) pos.x -= speed * dt;
    if (IsKeyDown(KEY_S)) pos.y += speed * dt;
    if (IsKeyDown(KEY_W)) pos.y -= speed * dt;

    setPos(pos.x, pos.y);
}

void Entity::update(float dt) {

}

bool Entity::checkWindowCollisions(int w, int h) {
  if(rect.x < 0 || rect.y < 0) { return true; }
  if(rect.x > w || rect.y > h) { return true; }
  return false;
}
Rectangle Entity::getBounds() const {
    return {
        rect.x - rect.width / 2.0f,
        rect.y - rect.height / 2.0f,
        rect.width,
        rect.height
    };
}

bool Entity::collidesWith(const Entity& other) const {
    return CheckCollisionRecs(getBounds(), other.getBounds());
}

bool Entity::playerWon() const { return 0; }
